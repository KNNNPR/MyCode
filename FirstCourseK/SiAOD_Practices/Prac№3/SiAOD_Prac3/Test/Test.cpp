#include <iostream>
#include <string>

int main()
{
    char d;
    std::string x;
    std::cin >> d;
    getline(std::cin, x);
    std::cout << x[0];
}

