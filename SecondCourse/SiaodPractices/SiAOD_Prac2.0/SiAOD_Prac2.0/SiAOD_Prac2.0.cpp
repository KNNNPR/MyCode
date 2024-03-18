#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

struct readerTicket
{
    int ticketNumber;
    std::string fio;
    std::string adress;

public:
    readerTicket(std::string fio, std::string adress, int ticketNumber)
    {
        this->ticketNumber = ticketNumber;
        this->adress = adress;
        this->fio = fio;
    }
    readerTicket()
    {
        this->ticketNumber = 0;
        this->adress = "";
        this->fio = "";
    }
};
struct table
{
    int numberTicket;
    std::streampos pos;
};

int generateRandomReaderTicket()
{
    int min = 10000;
    int max = 99999;
    return(min + rand() % (max - min + 1));
}
bool isUnique(int num, readerTicket* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i].ticketNumber == num) { return (false); }
    }
    return(true);
}
void writeToArrayTickets(readerTicket* arr, int length)
{
    int randNum;
    for (int i = 0; i < length; i++)
    {
        randNum = generateRandomReaderTicket();
        if (isUnique(randNum, arr, length))
        {
            arr[i].ticketNumber = randNum;
            arr[i].adress = "Preobrag.street, house num: " + std::to_string(i);
            arr[i].fio = "fio" + std::to_string(i);
        }
    }
}
bool writeToFileTickets(int length, readerTicket* arr)
{
    std::ofstream fout("readerTicketList.txt");
    if (!fout)
    {
        std::cout << "Coudn't open a file...";
        return(false);
    }
    for (int i = 0; i < length; i++)
    {
        fout << arr[i].ticketNumber << ' ' << arr[i].fio << ' ' << arr[i].adress << '\n';
    }
    std::cout << "Successfuly opend and written" << '\n';
    fout.close();
    return(true);
}
bool writeToFileTicketBin(int length, readerTicket* arr)
{
    std::ofstream foutBin("readerTicketList.bin", std::ios::binary);
    for (int i = 0; i < length; i++)
    {
        foutBin.write(reinterpret_cast<const char*>(&arr[i]), sizeof(readerTicket));
    }
    return(true);
    foutBin.close();
}
bool readFromFileTicketBin(int length, readerTicket* arr)
{
    readerTicket temp;
    int userKey;
    std::ifstream finBin("readerTicketList.bin", std::ios::binary);
    std::cout << "Enter key to linear search" << '\n';
    std::cin >> userKey;
    auto begin = std::chrono::high_resolution_clock::now();
    while (!finBin.eof())
    {
        finBin.read(reinterpret_cast<char*>(&temp), sizeof(readerTicket));
        if (temp.ticketNumber == userKey)
        {
            auto end = std::chrono::high_resolution_clock::now();
            std::cout << "ticket has been found!" << '\n';
            std::cout << "Adress: " << temp.adress << '\n';
            std::cout << "FIO: " << temp.fio << '\n';
            std::cout << "Ticket Number: " << temp.ticketNumber << '\n';
            std::chrono::duration<double> duration = end - begin;
            std::cout << "Time: " << duration.count() << '\n';
            return(true);
        }
    }
    std::cout << "Record was not found" << '\n';
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - begin;
    std::cout << "Time: " << duration.count();
    finBin.close();
    return(false);
}
bool comparator(table& a, table& b)
{
    return(a.numberTicket < b.numberTicket);
}
table* binarSearch(int key, std::vector<table>& a, int beg, int end)
{
    int resPos = (beg + end) / 2;
    if (beg > end) return(nullptr);
    if (a[resPos].numberTicket == key)
    {
        return(&a[resPos]);
    }
    else if (a[resPos].numberTicket < key)
    {
        binarSearch(key, a, resPos + 1, end);
    }
    else if (a[resPos].numberTicket > key)
    {
        binarSearch(key, a, beg, resPos - 1);
    }
}
void task3()
{
    std::vector<table> testVec;
    readerTicket a;
    std::streampos i = 0;
    std::ifstream finBinOne("readerTicketList.bin", std::ios::binary);
    while (finBinOne.read(reinterpret_cast<char*>(&a), sizeof(readerTicket)))
    {
        table b;
        b.numberTicket = a.ticketNumber;
        b.pos = i;
        testVec.push_back(b);
        i = finBinOne.tellg();
    }
    finBinOne.close();
    std::sort(testVec.begin(), testVec.end(), comparator);
    int keyO;
    std::cout << "Please, enter the key to binSearch" << '\n';
    std::cin >> keyO;
    table* result = binarSearch(keyO, testVec, 0, testVec.size());
    readerTicket k;
    std::ifstream finBinTwo("readerTicketList.bin", std::ios::binary);
    finBinTwo.seekg(result->pos);
    finBinTwo.read(reinterpret_cast<char*>(&k), sizeof(readerTicket));
    std::cout << k.fio << '\n';
    finBinTwo.close();
    std::cout << "Thats all, folks!";
}

int main()
{
    int amountOfTickets;
    std::cout << "You work with linear search and text/bin file" << '\n' << '\n';
    std::cout << "Enter amount of tickets" << '\n';
    std::cin >> amountOfTickets;
    readerTicket* arrayOfTickets = new readerTicket[amountOfTickets];
    std::cout << "Size of record: " << sizeof(readerTicket) << '\n' << '\n';
    writeToArrayTickets(arrayOfTickets, amountOfTickets);
    writeToFileTickets(amountOfTickets, arrayOfTickets);
    writeToFileTicketBin(amountOfTickets, arrayOfTickets);
    readFromFileTicketBin(amountOfTickets, arrayOfTickets);
}