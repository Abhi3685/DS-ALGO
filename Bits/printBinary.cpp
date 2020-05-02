#include <iostream>
using namespace std;

void printBinaryRepresentation(int num)
{
    if (num == 0)
        return;
    printBinaryRepresentation(num >> 1);
    num & 1 ? cout << 1 : cout << 0;
}

int main()
{
    int num = 10;
    printBinaryRepresentation(num);
    return 0;
}