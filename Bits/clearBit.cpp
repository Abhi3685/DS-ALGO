#include <iostream>
using namespace std;

void clearKthBit(int num, int k)
{
    int mask = 1 << k;
    num &= (~mask);
    cout << num;
}

int main()
{
    int num = 10;
    clearKthBit(num, 4);
    return 0;
}