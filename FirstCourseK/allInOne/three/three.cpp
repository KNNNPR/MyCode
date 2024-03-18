#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <string>
#include <chrono>
#include <algorithm>
int mini(int x, int y)
{
    return (x <= y) ? x : y;
};
struct record
{
    int snilsNum;
    char companyName[20];
    char lastNameOwner[20];
};
struct t
{
    int num;
    int pos;
};
bool sortKey(t a, t b)
{
    return (a.num < b.num);
}
bool uniqueSnils(int num, int n, int* snilses)
{
    for (int i = 0; i < n; i++)
    {
        if (snilses[i] == num) return (false);
    }
    return (true);
}
void generateRecordArray(record* recordArray, int n)
{
    std::string companise[3] = { "SNILS 1", "SNILS 2", "SNILS 3" };
    std::string lastnames[10] = { "KOZLOV", "BEBORV" , "XXX", "MOLOTOV", "AMMULA", "PIT", "VOLIC", "LELIC", "BOLIC", "DARKHOLME" };
    int* snilses = new int[n];
    int i = 0;
    while (i < n)
    {
        recordArray[i].snilsNum = 100 + rand() % 345668;
        if (uniqueSnils(recordArray[i].snilsNum, n, snilses))
        {
            snilses[i] = recordArray[i].snilsNum;
            std::string newComp = companise[rand() % 3];
            std::string newLastname = lastnames[rand() % 10];
            strcpy(recordArray[i].companyName, newComp.c_str());
            strcpy(recordArray[i].lastNameOwner, newLastname.c_str());
            i++;
        }
    }
}
t* generateTable(t* ans, FILE* filePtr, int n)
{
    ans = new t[n];
    record temp;
    for (int i = 0; i < n; i++)
    {
        fread(&temp, sizeof(record), 1, filePtr);
        ans[i].num = temp.snilsNum;
        ans[i].pos = i;
    }
    std::sort(ans, ans + n, sortKey);
    return(ans);
    std::cout << "sorted";
}
record GetLastRecord(FILE* filePtr, int n)
{
    fseek(filePtr, (n - 1) * sizeof(record), SEEK_SET);
    record last;
    fread(&last, sizeof(record), 1, filePtr);
    return (last);
}
record* linearSearch(FILE* filePtr, int n, int target)
{
    record ans;
    int i = 0;
    while (i < n)
    {
        size_t r = fread(&ans, sizeof(record), 1, filePtr);
        if (ans.snilsNum == target) return (&ans);
        if (r == 0) return (nullptr);
        i++;
    }
}
int Fibonachi(t* arr, int searchSnils, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = mini(offset + fibMMm2, n - 1);
        if (arr[i].num < searchSnils)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i].num > searchSnils)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return arr[i].pos;
    }
    if (fibMMm1 && arr[offset + 1].num == searchSnils)
        return arr[offset + 1].pos;
    return -1;
}
record getRecord(FILE* filePtr, int pos)
{
    fseek(filePtr, (pos) * sizeof(record), SEEK_SET);
    record temp;
    fread(&temp, sizeof(record), 1, filePtr);
    return temp;
}


int main()
{
    const char* fileName = "FileToWork.txt";
    int n[4] = { 100, 1000, 10000, 20000 };
    for (int i : n)
    {
        record* fillToFile = new record[i];
        generateRecordArray(fillToFile, i);
        FILE* filePtr = fopen(fileName, "wb");
        size_t bytes = fwrite(fillToFile, sizeof(record), i, filePtr);
        fclose(filePtr);
        filePtr = fopen(fileName, "rb");
        record lastRecord = GetLastRecord(filePtr, i);
        fclose(filePtr);
        std::cout << "Amount of records " << i << std::endl;
        std::cout << "Amount of bytes " << bytes << std::endl;
        std::cout << "Last Snils " << lastRecord.snilsNum << std::endl;
        std::cout << "Last Snils Name " << lastRecord.companyName << std::endl;
        std::cout << "Last Owner Name " << lastRecord.lastNameOwner << std::endl;
        std::cout << std::endl;
        std::cout.precision(10);
        std::cout << std::fixed;

        filePtr = fopen(fileName, "rb");
        t* array = NULL;
        std::cout << "Fib search" << std::endl;
        std::cout << "Enter searchSnils" << std::endl;
        auto start1 = std::chrono::steady_clock::now();
        array = generateTable(array, filePtr, i);
        auto end1 = std::chrono::steady_clock::now();
        std::chrono::duration<double> durr1 = end1 - start1;
        std::cout << "Time " << durr1.count() << std::endl;
        int searchSnils;
        std::cin >> searchSnils;
        int pos;
        auto start = std::chrono::steady_clock::now();
        pos = Fibonachi(array, searchSnils, i);
        auto end = std::chrono::steady_clock::now();
        lastRecord = getRecord(filePtr, pos);


        std::chrono::duration<double> durr = end - start;
        std::cout.precision(10);
        std::cout << std::fixed;
        std::cout << "Found Snils" << lastRecord.snilsNum << std::endl;
        std::cout << "Found Snils Name " << lastRecord.companyName << std::endl;
        std::cout << "Owner Name " << lastRecord.lastNameOwner << std::endl;
        std::cout <<"Time "<< durr.count() << std::endl;
        fclose(filePtr);
    }

}