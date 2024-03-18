#include <iostream>
#include <string>


bool isPalindrome(int x) {
    std::string prePalindrome = std::to_string(x);
    int startIndex = 0;
    int endIndex = prePalindrome.size() - 1;
    while (startIndex > endIndex)
    {
        if (prePalindrome[startIndex] != prePalindrome[endIndex])
        {
            return(false);
        }
        startIndex++;
        endIndex--;
    }
    return(true);
}


int main()
{
    std::cout << isPalindrome(-121);
}

