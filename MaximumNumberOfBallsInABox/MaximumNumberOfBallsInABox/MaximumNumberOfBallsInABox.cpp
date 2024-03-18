#include <iostream>
#include <vector>


int summOfDigits(int number)
{
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return(sum);
}


class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        int boxes[46] = { 0 };
        for (int i = lowLimit; i < highLimit + 1; i++)
        {
            int number = i;
            int sum = 0;
            while (number != 0)
            {
                sum += number % 10;
                number /= 10;
            }
            boxes[sum]++;
            sum = 0;
        }
        int max = 0;
        for (int i = 0; i < 46; i++)
        {
            if (boxes[i] > max) max = boxes[i];
        }
        std::cout << max;
    }
};


int main()
{
    int lowLimit;
    int highLimit;
    int boxes[46] = { 0 };


    std::cin >> lowLimit >> highLimit;

    for (int i = lowLimit; i < highLimit + 1; i++)
    {
        int index = summOfDigits(i);
        boxes[index]++;
    }

    int max = 0;
    for (int i = 0; i < 46; i++)
    {
        if (boxes[i] > max) max = boxes[i];
    }
    std::cout << max;
}