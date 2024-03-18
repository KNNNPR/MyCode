#include <iostream>
#include <fstream>
#include <set>

//----Структура записи в текстовом и бинарном файле----//
struct wordRecord
{
    char word[5];
    unsigned short int amountOfEntry;

public:
    wordRecord(std::string userWord, unsigned short int userAmountOfEntry)
    {
        for (int i = 0; i < userWord.size(); i++)
        {
            word[i] = userWord[i];
        }
        this->amountOfEntry = userAmountOfEntry;
    }
    wordRecord()
    {
        amountOfEntry = -1;
    }
};
//----Хэш-функция----//
unsigned short hashFunc(unsigned short int key, int tableSize)
{
    return(key % tableSize);
}
//----Структура записи в хэш-таблице----//
struct hashElement
{
    short int amountKey;
    std::streampos offset;

public:
    hashElement(unsigned short int userAmountOfEntry, std::streampos currOffset, int tableSize)
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
void searchElementFunc()
{

}
//----Функция рехеширования----//
hashElement* reHashFunc(hashElement* hashTable, int tableSize)
{
    hashElement* reHashTable = new hashElement[tableSize * 2];
    hashElement reHashElement;
    int newHashIndex;
    for (int i = 0; i < tableSize; i++)
    {
        if(hashTable[i].amountKey != -1)
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

int main()
{
    double amoutOfOccupiedElements = 0;
    int tableSize = 10;
    int userChoice;
    int newHashIndex;
    double overLoad;
    unsigned short int userAmountOfEntry;
    int userKeyToInsert;
    int userKeyToDelete;
    int userKeyToSearch;
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
            int recordAmount;
            std::cout << "Enter amount of records \n";
            std::cout << "Amount: ";
            std::cin >> recordAmount;
            std::ofstream fout(fileName, std::ios::binary);
            for (int i = 0; i < recordAmount; i++)
            {
                std::cout << "Enter the word and its aomunt of entry \n";
                std::cout << "Word: ";
                std::cin >> userWord;
                std::cout << "Amount: ";
                std::cin >> userAmountOfEntry;
                wordRecord userWordRecord(userWord, userAmountOfEntry);
                if (!fout.is_open()) { std::cout << "Sorry, can`t find your file \n"; break; }
                fout.seekp(currOffsetWrite);
                fout.write((char*)&userWordRecord, sizeof(wordRecord));
                currOffsetWrite = fout.tellp();
                std::cout << "CURRENT POS OF WRITE " << currOffsetWrite << "\n";
                std::cout << "Successfuly written to file!! \n";
                std::cout << "------------------------------------- \n";
            }
            fout.close();
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
                fin.read(reinterpret_cast<char*>(&toRead), sizeof(wordRecord));
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
            for(int i = 0; i < tableSize; i++)
            {
                if(hashTable[i].amountKey == ignore)
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
                            std::cout << "written record: " << currOffsetWrite << '\n';
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
            for (int i = 0; i < tableSize; i++)
            {
                if (hashTable[i].amountKey == userKeyToSearch)
                {
                    std::ifstream finSearch(fileName, std::ios::binary);
                    finSearch.seekg( hashTable[i].offset);
                    finSearch.read((char*)&toRead, sizeof(wordRecord));
                    std::cout << "Record element with key " << toRead.amountOfEntry << " has been found \n";
                    std::cout << "Hash index of element: " << i << '\n';
                    std::cout << "------------------------------------- \n";
                    currOffsetRead = 0;
                    finSearch.close();
                    break;
                }
            }
            std::cout << "Unfortunately, can`t find element \n";
            std::cout << "------------------------------------- \n";
            break;
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

    } while (userChoice == 0 || userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 4);
}