#include <iostream>
#include <fstream>
#include <chrono>
#include<random>

unsigned short SubTaskOne(unsigned short UserNum)
{
    return(0x0078 | UserNum);
}
unsigned short SubTaskTwo(unsigned short UserNum)
{
    return(0xe7fd & UserNum);//2045//
}
unsigned short SubTaskThree(unsigned short UserNum)
{
    return(UserNum << 5);
}
unsigned short SubTaskFour(unsigned short UserNum)
{
    return(UserNum >> 5);
}
unsigned short SubTaskFive(unsigned short UserNum, unsigned short PositionOfBit)
{
    unsigned short bitMask = 1;
    for (int i = 0; i < PositionOfBit; i++)
    {
        bitMask *= 2;
    }
    return(bitMask ^ UserNum);
    /*UserNum << PositionOfBit;*/
}
void initializedBits(char* bits)
{
    for (int i = 0; i < 1000000; i++)
    {
        bits[i] = 0;
    }
}
int random() //генератор рандомного числа
{
    std::random_device rand_dev;
    std::mt19937 gen(rand_dev());
    std::uniform_int_distribution<int> random(100000, 999999);
    return random(gen);
}

int main()
{
    int Control;
    do
    {
        std::cout << "Enter number of subtask" << std::endl;
        std::cin >> Control;
        switch (Control)
        {
        case 1:
        {
            int subTastOneControl;
            bool flagSubTaskOne = true;
            unsigned short UserNum;
            unsigned short bitPlace;
            while (flagSubTaskOne)
            {
                std::cout << "Enter number of option in subTask one" << std::endl;
                std::cin >> subTastOneControl;
                switch (subTastOneControl)
                {
                case 1:
                {
                    std::cout << "Enter Your number" << std::endl;
                    std::cin >> UserNum;
                    std::cout << "Here is your number after affected by mask: " << SubTaskOne(UserNum) << std::endl;
                    break;
                }
                case 2:
                {
                    std::cout << "Enter Your number" << std::endl;
                    std::cin >> UserNum;
                    std::cout << "Here is your number after affected by mask: " << SubTaskTwo(UserNum) << std::endl;
                    break;
                }
                case 3:
                {
                    std::cout << "Enter Your number" << std::endl;
                    std::cin >> UserNum;
                    std::cout << "Here is your number after affected by mask: " << SubTaskThree(UserNum) << std::endl;
                    break;
                }
                case 4:
                {
                    std::cout << "Enter Your number" << std::endl;
                    std::cin >> UserNum;
                    std::cout << "Here is your number after affected by mask: " << SubTaskFour(UserNum) << std::endl;
                    break;
                }
                case 5:
                {
                    std::cout << "Enter Your number" << std::endl;
                    std::cin >> UserNum;
                    std::cin >> bitPlace;
                    std::cout << "Here is your number after affected by mask: " << SubTaskFive(UserNum, bitPlace) << std::endl;
                    break;
                }
                }
            }
        }
        case 2:
        {
            bool subTaskFlag = true;
            int subTaskTwoControl;
            int length;
            while (subTaskFlag)
            {
                std::cout << "1 - Array" << '\n';
                std::cout << "2 - Array 64" << '\n';
                std::cin >> subTaskTwoControl;
                switch (subTaskTwoControl)
                {
                case 1:
                {
                    std::cout << "Enter length of array" << '\n';
                    std::cin >> length;
                    int* userArray = new int[length];
                    unsigned char userSort = 0;
                    for (int i = 0; i < length; i++)
                    {
                        std::cin >> userArray[i];
                        userSort |= (1 << userArray[i]);
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        if (userSort & (1 << i))
                        {
                            std::cout << i << ' ';
                        }
                    }
                    std::cout << '\n';
                    break;
                }
                case 2:
                {

                    std::cout << "Enter length of array" << '\n';
                    std::cin >> length;
                    int* userArray = new int[length];
                    unsigned char userSort[8] = { 0,0,0,0,0,0,0,0 };
                    for (int i = 0; i < length; i++)
                    {
                        std::cin >> userArray[i];
                        userSort[(userArray[i] / 8)] |= (1 << userArray[i] % 8);
                    }
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (userSort[i] & (1 << j))
                            {
                                std::cout << i * 8 + j << ' ';
                            }
                        }
                    }
                    std::cout << '\n';
                    break;
                }
                case 3:
                {
                    subTaskFlag = false;
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            char sortedBits[1000000];
            int anotherInt = (pow(10, 7) + 7) / 8;
            initializedBits(sortedBits);
            std::ofstream f2("unsortedNumsByString.txt");

            for (int i = 0; i < 100000; i++) 
            {
                f2 << random() << '\n';
            }
            f2.close();
            std::ifstream fin;
            fin.open("unsortedNumsByString.txt");
            if (fin.is_open())
            {
                std::cout << "file opend" << '\n';
            }
            while(fin >> anotherInt)
            {
                sortedBits[(anotherInt / 8)] |= (1 << anotherInt % 8);
            }
            fin.close();
            std::ofstream fout("sortedNumsByString.txt");
            auto start = std::chrono::steady_clock::now();
            for (int i = 0; i < 1000000; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    if (sortedBits[i] & (1 << j))
                    {
                        fout << i * 8 + j << '\n';
                    }
                }
            }
            auto end = std::chrono::steady_clock::now();
            std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " miliseconds" << '\n';
            fout.close();
            break;
        }
        case 4:
        {
            std::exit(0);
        }
        }

    } while (Control == 1 || Control == 2 || Control == 3 || Control == 4);

}