#include <iostream>
#include <fstream>

#include <set>
#include <chrono>

//1000041
// 
// 1005574
// 
//1029326

//----Структура записи в текстовом и бинарном файле----//
struct wordRecord
{
    /*char word[5];*/
    char word;
    /*unsigned short*/ int amountOfEntry;

public:
    wordRecord(/*std::string*/char userWord, /*unsigned short*/ int userAmountOfEntry)
    {
        /*for (int i = 0; i < userWord.size(); i++)
        {
            word[i] = userWord[i];
        }*/
        word = userWord;
        this->amountOfEntry = userAmountOfEntry;
    }
    wordRecord()
    {
        amountOfEntry = -1;
    }
};
//----Хэш-функция----//
/*unsigned short*/int hashFunc(/*unsigned short*/ int key, int tableSize)
{
    return(key % tableSize);
}
//----Структура записи в хэш-таблице----//
struct hashElement
{
    /*short*/ int amountKey;
    std::streampos offset;

public:
    hashElement(/*unsigned short*/ int userAmountOfEntry, std::streampos currOffset, int tableSize)
    {
        this->amountKey = userAmountOfEntry;
        this->offset = currOffset;
    }
    hashElement()
    {
        this->amountKey = -1;
        this->offset = -1;
    }
};
//----Функция вставки элемента в хэш-таблицу----//
void addHashElement(hashElement newHashElement, int newHashIndex, hashElement* hashTable, int tableSize)
{
    if (hashTable[newHashIndex].offset == -1)
    {
        hashTable[newHashIndex] = newHashElement;
    }
    else if (hashTable[newHashIndex].amountKey != -1)
    {
        addHashElement(newHashElement, newHashIndex + 1, hashTable, tableSize);
    }
}
//----Функция добавления элемента в хэш-таблицу----//
void addElementFunc()
{

}
//----Функция удаления элемента из хэш-таблицы----//
void removeElementFunc()
{

}
//----Функция поиска элемента в хэш-таблице----//
int searchElementFunc(hashElement* hashTable, int tableSize, int userKeyToSearch, int searchIndex)
{
    if (hashTable[searchIndex].amountKey == userKeyToSearch) return(searchIndex);
    else if (hashTable[searchIndex].amountKey == -1) return(-1);
    else searchElementFunc(hashTable, tableSize, userKeyToSearch, searchIndex + 1);
}
//----Функция рехеширования----//
hashElement* reHashFunc(hashElement* hashTable, int tableSize)
{
    hashElement* reHashTable = new hashElement[tableSize * 2];
    hashElement reHashElement;
    int newHashIndex;
    for (int i = 0; i < tableSize; i++)
    {
        if (hashTable[i].amountKey != -1)
        {
            reHashElement.amountKey = hashTable[i].amountKey;
            reHashElement.offset = hashTable[i].offset;
            newHashIndex = hashFunc(hashTable[i].amountKey, tableSize * 2);
            addHashElement(reHashElement, newHashIndex, reHashTable, tableSize * 2);
        }
    }
    return(reHashTable);
}
//----Функция генерации случайного числа----//
unsigned long long Randomizer()
{
    int min = 1000000;
    int max = 9999999;
    return min + rand() % (max - min + 1);
}

int main()
{
    double amoutOfOccupiedElements = 0;
    int tableSize = 10;
    int userChoice;
    int newHashIndex;
    double overLoad;
    int userAmountOfEntry;
    int userKeyToInsert;
    int userKeyToDelete;
    int userKeyToSearch;
    char userChar;
    hashElement* hashTable = new hashElement[tableSize];
    wordRecord toRead;
    std::streampos currOffsetWrite = 0;
    std::streampos currOffsetRead = 0;
    std::string userWord;
    std::string fileName = "wordRecordList.bin";
    std::cout << "Work with hash-table and binary file \n";
    std::cout << "------------------------------------- \n";
    do
    {
        std::cout << "Enter what you want to do with \n";
        std::cout << "0 - fill binfile \n";
        std::cout << "1 - add record to hash table \n";
        std::cout << "2 - delete record through hash table \n";
        std::cout << "3 - search record through the hash-table \n";
        std::cout << "4 - show the hash-table \n";
        std::cout << "------------------------------------- \n";
        std::cin >> userChoice;
        switch (userChoice)
        {
        case 0:
        {
            std::ofstream fileBinary(fileName, std::ios::binary);
            int quant = 1000;
            std::set<int> unique;
            wordRecord record;
            for (int i = 0; i < quant; ++i)
            {
                do {
                    record.amountOfEntry = Randomizer();
                } while (unique.count(record.amountOfEntry) > 0);
                unique.insert(record.amountOfEntry);
                record.word = 'f';
                fileBinary.seekp(currOffsetWrite);
                fileBinary.write(reinterpret_cast<const char*>(&record), sizeof(wordRecord));
                currOffsetWrite = fileBinary.tellp();
            }
            std::cout << "CURRENT POS OF WRITE " << currOffsetWrite << "\n";
            std::cout << "Okey. \n";
            break;
        }
        case 1:
        {

            std::cout << "Enter the key of record \n";
            std::cout << "Key: ";
            std::cin >> userKeyToInsert;
            std::ifstream fin(fileName, std::ios::binary);
            while (!fin.eof())
            {
                fin.seekg(currOffsetRead);
                fin.read((char*)&toRead, sizeof(wordRecord));
                if (toRead.amountOfEntry == userKeyToInsert)
                {
                    amoutOfOccupiedElements++;
                    overLoad = amoutOfOccupiedElements / tableSize;
                    std::cout << "OverLoad: " << overLoad << '\n';
                    if (overLoad >= 0.75)
                    {
                        hashTable = (hashElement*)realloc(hashTable, sizeof(hashElement) * tableSize * 2);
                        hashTable = reHashFunc(hashTable, tableSize);
                        tableSize *= 2;
                    }
                    hashElement toInsert;
                    toInsert.amountKey = toRead.amountOfEntry;
                    toInsert.offset = currOffsetRead;
                    newHashIndex = hashFunc(toInsert.amountKey, tableSize);
                    addHashElement(toInsert, newHashIndex, hashTable, tableSize);
                    currOffsetRead = 0;
                    std::cout << "Record of your key has been successfuly added to hash-table \n";
                    std::cout << "------------------------------------- \n";
                    break;
                }
                currOffsetRead = fin.tellg();
            }
            currOffsetRead = 0;
            std::cout << "Sorry, we can`t find the record \n";
            std::cout << "------------------------------------- \n";
            fin.close();
            break;
        }
        case 2:
        {
            int ignore;
            std::cin >> ignore;
            for (int i = 0; i < tableSize; i++)
            {
                if (hashTable[i].amountKey == ignore)
                {
                    std::ifstream finRead(fileName, std::ios::binary);
                    std::ofstream foutWrite("temp.bin", std::ios::binary | std::ios::trunc);
                    wordRecord tempRecord;
                    finRead.read((char*)&tempRecord, sizeof(wordRecord));
                    while (!finRead.eof())
                    {
                        std::cout << "Readen record: " << tempRecord.amountOfEntry << '\n';
                        if (ignore == tempRecord.amountOfEntry)
                        {
                            std::cout << "Yessss \n";
                            currOffsetWrite += sizeof(wordRecord);
                            foutWrite.seekp(currOffsetWrite);
                        }
                        else
                        {
                            foutWrite.write((char*)&tempRecord, sizeof(wordRecord));
                            currOffsetWrite = foutWrite.tellp();
                        }
                        finRead.read((char*)&tempRecord, sizeof(wordRecord));
                    }
                    currOffsetWrite = 0;
                    finRead.close();
                    foutWrite.close();
                    remove("wordRecordList.bin");
                    rename("temp.bin", "wordRecordList.bin");
                    hashTable[i].amountKey = -1;
                    hashTable[i].offset = -1;
                    break;
                }
            }
            break;
        }
        case 3:
        {
            std::cout << "Enter the key you want to search \n";
            std::cout << "Key: ";
            std::cin >> userKeyToSearch;
            auto start = std::chrono::high_resolution_clock::now();
            int searchIndex;
            std::cout << "Enter the key you want to search \n";
            std::cout << "Key: ";
            std::cin >> userKeyToSearch;
            searchIndex = searchElementFunc(hashTable, tableSize, userKeyToSearch, hashFunc(userKeyToSearch, tableSize));
            if (searchIndex == -1) std::cout << "Sorry \n";
            else std::cout << "Index: " << searchIndex << '\n';
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << elapsedMs.count() << '\n';
            break;
        }
        case 4:
        {
            std::cout << "----HASH-TABLE---- \n";
            std::cout << "------------------------------------- \n";
            for (int i = 0; i < tableSize; i++)
            {
                std::cout << i << "--> " << hashTable[i].amountKey << "  " << hashTable[i].offset << '\n';
            }
            std::cout << "------------------------------------- \n";
            break;
        }
        }

    } while (userChoice == 0 || userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 4 || userChoice == 5);
}