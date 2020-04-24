#include <iostream>
using namespace std;

void pattern_01(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_02(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

void pattern_03(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

void pattern_04(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << to_string(i) + " ";
        }
        cout << endl;
    }
}

void pattern_05(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << to_string(count++) + " ";
        }
        cout << endl;
    }
}

void pattern_06(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << (char)('A' + i) << " ";
        }
        cout << endl;
    }
}

void pattern_07(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)('A' + count++) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    // Simple pyramid pattern
    // pattern_01(n);

    // After 180 degree rotation
    // pattern_02(n);

    // Printing Triangle
    // pattern_03(n);

    // Number Pattern
    // pattern_04(n);

    // Numbers without re assigning
    // pattern_05(n);

    // Character Pattern
    // pattern_06(n);

    // Continuous Character pattern
    // pattern_07(n);

    return 0;
}