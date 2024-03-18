#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <set> //для набора уникальных элементов
#include <chrono> // Для измерения времени
#include <algorithm>

using namespace std;

//Структура записи - Книга: уникальный ISBN, Автор, Название
struct BookRecord
{
    long long ISBN = 0;
    string author;
    string name;
};

//ISBN, состоящий из 12 чисел
unsigned long long Randomizer()
{
    long long min = 100000000000;
    long long max = 999999999999;
    return min + rand() % (max - min + 1);
}

struct OffsetTableEntry
{
    long long ISBN = 0;
    streampos offset; //streampos хранит позицию(смещение) в бинарном файле
};

//функция для сортировки таблицы смещений по ключу
bool CompareByISBN(const OffsetTableEntry& a, const OffsetTableEntry& b)
{
    return a.ISBN < b.ISBN;
}

streampos ModifiedBinarySearch(const vector<OffsetTableEntry>& offsetTable, long long key) //однородный бинарный поиск с применением таблицы смещений 
{
    size_t N = offsetTable.size();
    vector<size_t> delta(N);

    // Вычисляем значения delta заранее
    for (size_t j = 1; j <= N; j++)
    {
        delta[j - 1] = (N + (1ULL << (j - 1))) / (1ULL << j); //вычисляем j-е значение по формуле (N+2^(j-1))/2^j
    }

    size_t i = delta[0];
    size_t j = 2; //начиная с первого элемента [j-1]

    while (delta[j - 1] > 0)
    {
        if (offsetTable[i].ISBN == key)
        {
            // Запись найдена, возвращаем смещение
            return offsetTable[i].offset;
        }
        else if (offsetTable[i].ISBN < key)
        {
            // Сдвигаемся вправо, увеличиваем i и j
            i += delta[j - 1];
            j++;
        }
        else
        {
            // Сдвигаемся влево, уменьшаем i и увеличиваем j
            i -= delta[j - 1];
            j++;
        }
    }

    // Запись не найдена
    return -1;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream fileText("text.txt"); //текстовый файл
    if (!fileText)
    {
        cout << "Текстовый файл не удалось открыть для записи." << endl;
        return 1;
    }
    cout << "Текстовый файл успешно открыт для записи." << endl << endl;

    //открываем файл для записи в бинарном режиме (флаг - ios::binary)
    ofstream fileBinaryOUT("text.bin", ios::binary); //бинарный файл
    if (!fileBinaryOUT) {
        cout << "Бинарный файл не удалось открыть для записи." << endl;
        return 1;
    }
    cout << "Бинарный файл успешно открыт для записи." << endl << endl;

    int quant = 10000; //количество записей
    set<int> unique;

    BookRecord record;
    for (int i = 0; i < quant; ++i)
    {
        do {
            record.ISBN = Randomizer();
        } while (unique.count(record.ISBN) > 0);
        unique.insert(record.ISBN);
        record.author = "Автор_" + to_string(i);
        record.name = "Название_" + to_string(i);

        fileText << record.ISBN << ' ' << record.author << ' ' << record.name << '\n';

        fileBinaryOUT.write(reinterpret_cast<const char*>(&record), sizeof(record));
    }
    cout << "Генерация текстового и бинарного файла завершена." << endl << endl;

    fileText.close();
    fileBinaryOUT.close();

    vector<OffsetTableEntry> offsetTable; // Таблица смещений

    ifstream fileBinaryIN("text.bin", ios::binary);
    if (!fileBinaryIN)
    {
        cout << "Бинарный файл не удалось открыть для чтения." << endl;
        return 1;
    }
    cout << "Бинарный файл успешно открыт для чтения." << endl << endl;


    streampos currentOffset = 0; //изначальная позиция смещения
    while (fileBinaryIN.read(reinterpret_cast<char*>(&record), sizeof(record)))
    {
        OffsetTableEntry entry; //создание записи в таблице смещений
        entry.ISBN = record.ISBN;
        entry.offset = currentOffset;
        offsetTable.push_back(entry);

        currentOffset = fileBinaryIN.tellg(); //Обновление позиции чтения для следующей записи
    }

    //сортировка массива по ключу(для бинарного поиска)
    sort(offsetTable.begin(), offsetTable.end(), CompareByISBN);

    fileBinaryIN.close();

    //бинарный однородный поиск по ключу
    cout << "----Поиск книги по ISBN----" << endl << endl;
    long long key;
    cout << "Введите ISBN-номер книги (12 чисел): ";
    cin >> key;

    auto start = chrono::high_resolution_clock::now();

    streampos offset = ModifiedBinarySearch(offsetTable, key);

    //если запись нашлась
    if (offset != -1)
    {
        ifstream fileBinaryIN("text.bin", ios::binary);
        if (fileBinaryIN)
        {
            fileBinaryIN.seekg(offset); //установка позиции чтения на место найденной записи

            if (fileBinaryIN.read(reinterpret_cast<char*>(&record), sizeof(record))) //считывание записи
            {
                cout << endl << "Запись книги найдена." << endl;
                cout << "Номер ISBN: " << record.ISBN << endl;
                cout << "Автор книги: " << record.author << endl;
                cout << "Название книги: " << record.name << endl;

                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> duration = end - start;
                cout << "Время выполнения поиска: " << duration.count() << " секунд." << endl;

                fileBinaryIN.close();
                return 0;
            }
        }
    }

    cout << "Запись с номером " << key << " не была найдена." << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Время выполнения поиска: " << duration.count() << " секунд." << endl;

    fileBinaryIN.close();

    return 0;
}
