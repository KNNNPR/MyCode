#include <iostream>

int binSearch(int* a, int i, int key, int delta)
{
    if(a[i] == key) return(i);
    if (delta == 0) return(-1);
    if (a[i] < key) return(binSearch(a, i + delta / 2 + 1, key, delta / 2));
    if (a[i] > key) return(binSearch(a, i - delta / 2 - 1, key, delta / 2));
}

int main()
{
    int array[10] = { 10, 12, 15, 18, 20, 32, 45, 60, 70, 81};
    std::cout << binSearch(array, 4, 45, 4);
}