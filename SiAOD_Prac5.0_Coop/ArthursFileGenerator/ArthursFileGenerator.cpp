#include <iostream>
#include <fstream>
#include <set>
#include <random>
#include <cstring>

using namespace std;

struct bookRecord
{
    long long ISBN;
    char author[15];
    char name[18];
    unsigned short int year;

public:
    bookRecord(long long userISBN, unsigned short int userYear)
    {
        // Инициализация строк с фиксированными значениями
        const char* defaultAuthor = "Автор_в_дереве";
        const char* defaultName = "Название_в_дереве";

        // Копирование значений в массивы символов
        strcpy_s(author, defaultAuthor);
        strcpy_s(name, defaultName);

        this->year = userYear;
        this->ISBN = userISBN;
    }

    bookRecord()
    {
        ISBN = -1;
    }
};

struct Node
{
    long long key;
    streampos offset; // Ссылка на запись в файле
    Node* left;
    Node* right;

    Node(long long k, streampos o) : key(k), offset(o), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node* root;

    // Функции для работы с деревом
    Node* insert(Node* node, long long key, streampos offset);
    Node* search(Node* node, long long key);
    Node* remove(Node* node, long long key);
    void display(Node* node, int level);

public:
    BinarySearchTree() : root(nullptr) {}

    // Функции вставки, поиска, удаления и отображения
    void insert(long long key, streampos offset);
    void search(long long key);
    void remove(long long key);
    void display();
};

// Функция вставки в бинарное дерево
Node* BinarySearchTree::insert(Node* node, long long key, streampos offset)
{
    if (node == nullptr)
        return new Node(key, offset);

    if (key < node->key)
        node->left = insert(node->left, key, offset);
    else if (key > node->key)
        node->right = insert(node->right, key, offset);

    return node;
}

void BinarySearchTree::insert(long long key, streampos offset)
{
    root = insert(root, key, offset);
}

// Функция поиска в бинарном дереве
Node* BinarySearchTree::search(Node* node, long long key)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->key == key) {
        return node;
    }

    if (key < node->key)
        return search(node->left, key);

    return search(node->right, key);
}

void BinarySearchTree::search(long long key)
{
    Node* result = search(root, key);
    if (result != nullptr)
    {
        // Считывание записи из файла по найденной ссылке
        ifstream fin("bookRecordList.bin", ios::binary);
        fin.seekg(result->offset);
        bookRecord foundRecord;
        fin.read((char*)&foundRecord, sizeof(bookRecord));
        fin.close();

        // Вывод информации о найденной записи
        cout << "ISBN: " << foundRecord.ISBN << endl;
        cout << "Название: " << foundRecord.name << endl;
        cout << "Автор: " << foundRecord.author << endl;
        cout << "Год издания: " << foundRecord.year << endl;

        fin.close();
    }
    else
    {
        cout << "Книга с ISBN " << key << " не найдена." << endl;
    }
}

// Функция удаления из бинарного дерева
Node* BinarySearchTree::remove(Node* node, long long key)
{
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else
    {
        // Найден узел для удаления
        if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // У узла есть два потомка
        Node* temp = node->right;
        while (temp->left != nullptr)
            temp = temp->left;

        node->key = temp->key;
        node->offset = temp->offset;
        node->right = remove(node->right, temp->key);
    }

    return node;
}

void BinarySearchTree::remove(long long key)
{
    root = remove(root, key);
}

// Функция отображения структуры дерева
void BinarySearchTree::display(Node* node, int level)
{
    if (node != nullptr)
    {
        display(node->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << node->key << endl;
        display(node->left, level + 1);
    }
}

void BinarySearchTree::display()
{
    display(root, 0);
}

unsigned short int generateYear()
{
    // Создаем генератор случайных чисел
    random_device rd;
    mt19937 gen(rd());

    // Задаем диапазон генерации чисел
    uniform_int_distribution<> dis(850, 2023);

    // Генерируем случайное число (год)
    return static_cast<unsigned short int>(dis(gen));
}

long long generateISBN()
{
    // Создаем генератор случайных чисел
    std::random_device rd;
    std::mt19937_64 gen(rd());

    // Задаем диапазон для генерации чисел (12-значный ISBN)
    std::uniform_int_distribution<long long> dis(100000000000, 999999999999);

    // Генерируем случайный 12-значный ISBN
    return dis(gen);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int userChoice;
    long long userISBN;
    long long userKeyToInsert;
    long long userKeyToDelete;
    long long userKeyToSearch;
    bookRecord toRead;
    streampos currOffsetWrite = 0;
    streampos currOffsetRead = 0;
    string userAuthor;
    string userName;
    unsigned short int userYear = 0;
    string fileName = "bookRecordList.bin";

    BinarySearchTree bst;

    do
    {
        cout << "Введите предпочитаемое действие \n";
        cout << "0 - заполнить бинарный файл \n";
        cout << "1 - заполнить бинарное дерево из файла \n";
        cout << "2 - поиск по ISBN в дереве и вывод информации \n";
        cout << "3 - удаление по ISBN из дерева \n";
        cout << "4 - отображение структуры дерева \n";
        cout << "------------------------------------- \n";
        cin >> userChoice;

        switch (userChoice)
        {
        case 0:
        {
            int recordAmount;
            cout << "Введите количество записей: ";
            cin >> recordAmount;
            ofstream fout(fileName, ios::binary);
            for (int i = 0; i < recordAmount; i++)
            {
                cout << "Генерация записей. \n";
                userYear = generateYear();
                cout << "Cгенерированный год: " << userYear << endl;
                userISBN = generateISBN();
                cout << "Cгенерированный ISBN: " << userISBN << endl;
                bookRecord userbookRecord(userISBN, userYear);
                cout << userbookRecord.name << " " << userbookRecord.author << endl;
                if (!fout.is_open()) { cout << "Не удалось открыть файл. \n"; break; }
                fout.seekp(currOffsetWrite);
                fout.write((char*)&userbookRecord, sizeof(bookRecord));
                currOffsetWrite = fout.tellp();
                cout << "Позиция записи " << currOffsetWrite << "\n";
                cout << "Успешно записано в файл. \n";
                cout << "------------------------------------- \n";
            }
            fout.close();
            break;
        }
        case 1:
            // Заполнение бинарного дерева из файла
        {
            ifstream fin(fileName, ios::binary);
            if (!fin.is_open()) { cout << "Не удалось открыть файл. \n"; break; }

            while (fin.read((char*)&toRead, sizeof(bookRecord)))
            {
                bst.insert(toRead.ISBN, currOffsetRead);
                currOffsetRead = fin.tellg();
            }

            fin.close();
            break;
        }

        case 2:
            // Поиск по ISBN в дереве и вывод информации
            cout << "Введите ISBN для поиска: ";
            cin >> userKeyToSearch;
            bst.search(userKeyToSearch);
            break;

        case 3:
            // Удаление по ISBN из дерева
            cout << "Введите ISBN для удаления: ";
            cin >> userKeyToDelete;
            bst.remove(userKeyToDelete);
            cout << "Запись с ISBN " << userKeyToDelete << " удалена из дерева.\n";
            break;

        case 4:
            // Отображение структуры дерева
            bst.display();
            break;
        }

    } while (userChoice == 0 || userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 4);

    return 0;
}
