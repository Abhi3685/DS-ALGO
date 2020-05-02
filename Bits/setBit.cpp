#include <iostream>
using namespace std;

void setKthBit(int num, int k)
{
    int mask = 1 << k;
    num |= mask;
    cout << num;
}

int main()
{
    int num = 10;
    setKthBit(num, 4);
    return 0;
}