#include <iostream>
using namespace std;

void reverseBits(int *n)
{
    for (int i = 0, j = 31; i < 16, j >= 16; i++, j--)
    {
        int m1 = 1 << i;
        int m2 = 1 << j;
        int bit1, bit2;
        bit1 = (*n & m1) ? 1 : 0;
        bit2 = (*n & m2) ? 1 : 0;
        if (bit1 != bit2)
        {
            if (bit1 == 1)
            {
                *n |= m2;
                *n &= (~m1);
            }
            else
            {
                *n |= m1;
                *n &= (~m2);
            }
        }
    }
}

int main()
{
    int num = 5; // Binary: 00000000000000000000000000000101
    reverseBits(&num);
    cout << num << endl; // Binary: 10100000000000000000000000000000
    return 0;
}