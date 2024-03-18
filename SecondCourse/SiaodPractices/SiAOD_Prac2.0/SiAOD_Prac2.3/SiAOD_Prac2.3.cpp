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
void binarFileTableSearch()
{
    std::vector<table> dopStruct;
    readerTicket tempTicket;
    std::streampos current = 0;
    int key;
    std::ifstream finBin("readerTicketList.bin", std::ios::binary);
    while (finBin.read(reinterpret_cast<char*>(&tempTicket), sizeof(readerTicket)))
    {
        table tempTable;
        tempTable.numberTicket = tempTicket.ticketNumber;
        tempTable.pos = current;
        dopStruct.push_back(tempTable);
        current = finBin.tellg();
    }
    finBin.close();
    std::sort(dopStruct.begin(), dopStruct.end(), comparator);
    std::cin >> key;
    std::streampos targetIndex = binarSearch(key, dopStruct, 0, dopStruct.size())->pos;
    std::ifstream finBinTwo("readerTicketList.bin", std::ios::binary);
    finBinTwo.seekg(targetIndex);
    finBinTwo.read(reinterpret_cast<char*>(&tempTicket), sizeof(readerTicket));
    std::cout << tempTicket.fio;
    finBinTwo.seekg(finBinTwo.eof());
    finBinTwo.close();
    //std::vector<table> usless;
    //readerTicket temp;
    //readerTicket result;
    //int key;
    //int i = 0;
    //std::streampos current = 0;
    //std::ifstream finBin("readerTicketList.bin", std::ios::binary);
    //while (finBin.read(reinterpret_cast<char*>(&temp), sizeof(readerTicket)))
    //{
    //    table tempk;
    //    tempk.numberTicket = temp.ticketNumber;
    //    tempk.pos = current;
    //    tempk.numPos = i;
    //    usless.push_back(tempk);
    //    i++;
    //    current = finBin.tellg();
    //}
    //finBin.close();
    //std::sort(usless.begin(), usless.end(), comparator);
    //std::cin >> key;
    //if (binarSearch(key, usless, 0, usless.size() - 1) == nullptr)
    //{
    //    std::cout << "Record was not found" << '\n';
    //    return(false);
    //}
    //else
    //{
    //    std::streampos  i = binarSearch(key, usless, 0, usless.size() - 1)->pos;
    //    std::ifstream finBinTwo("readerTicketList.bin", std::ios::binary);
    //    finBinTwo.seekg(i);
    //    if (finBinTwo.read(reinterpret_cast<char*>(&result), sizeof(result)))
    //    {
    //        /*std::cout << result.adress << '\n';
    //        std::cout << result.fio << '\n';*/
    //        std::cout << result.ticketNumber << '\n';
    //    }
    //    return(true);
    //    finBinTwo.close();
    //}
}

int main()
{
    binarFileTableSearch();
}