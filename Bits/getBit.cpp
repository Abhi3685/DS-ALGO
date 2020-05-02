#include <iostream>
using namespace std;

void getKthBit(int num, int k)
{
    int mask = 1 << k;
    (num & mask) ? cout << 1 : cout << 0;
}

int main()
{
    int num = 10;
    getKthBit(num, 1);
    return 0;
}