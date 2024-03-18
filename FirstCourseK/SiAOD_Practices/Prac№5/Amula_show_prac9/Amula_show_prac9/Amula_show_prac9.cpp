#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <string>

struct record
{
    int snilsNum;
    char companyName[20];
    char lastNameOwner[20];
};
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

int main()
{

    /// INICIALIZATION FILE NAME
    const char* fileName = "FileToWork.txt";
    /// ALL START THINGS TO OPEN AND WRITE TO FILE
    int n = 100;
    record* fillToFile = new record[n];
    generateRecordArray(fillToFile, n);
    /// OPEN AND WRITE TO FILE
    FILE* filePtr = fopen(fileName, "wb");
    size_t bytes = fwrite(fillToFile, sizeof(record), n, filePtr);
    fclose(filePtr);
    /// READFILE
    filePtr = fopen(fileName, "rb");
    record lastRecord = GetLastRecord(filePtr, n);
    fclose(filePtr);
    std::cout << n << ' ' << bytes << ' ' << std::endl;
    std::cout << lastRecord.snilsNum << std::endl;
    std::cout << lastRecord.companyName << std::endl;
    std::cout << lastRecord.lastNameOwner << std::endl;





    filePtr = fopen(fileName, "rb");
    int searchSnils;
    std::cin >> searchSnils;
    lastRecord = *linearSearch(filePtr, n, searchSnils);
    std::cout << lastRecord.snilsNum << std::endl;
    std::cout << lastRecord.companyName << std::endl;
    std::cout << lastRecord.lastNameOwner << std::endl;
    fclose(filePtr);
}
