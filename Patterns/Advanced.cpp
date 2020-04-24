#include <iostream>
#include <vector>
using namespace std;

void pattern_1_1(int l, int b)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_1_2(int l, int b)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (i == 0 || i == b - 1)
            {
                cout << "* ";
                continue;
            }
            if (j == 0 || j == l - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_2_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern_2_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0 || j == 0 || j == n - i - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_2_3(int n)
{
    for (int i = n; i >= 1; i--)
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

void pattern_2_4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
                cout << " ";
            else if (j == n - i || j == n || i == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_3_1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void pattern_3_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp = i + 1;
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
                cout << "  ";
            else
                cout << tmp++ << " ";
        }
        tmp--;
        for (int j = 1; j <= i; j++)
        {
            cout << --tmp << " ";
        }
        cout << endl;
    }
}

void pattern_3_3(int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp = 1;
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
                cout << " ";
            else if (j == n - i || j == n || i == n - 1)
                cout << tmp++ << " ";
            else
            {
                tmp++;
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void pattern_4_1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (int j = i - 1; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern_4_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
                cout << "*";
            if (j < n - i)
                cout << "*";
            else
                cout << i + 1 << "*";
        }
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
                cout << "*";
        }
        cout << endl;
    }
}

void pattern_5_1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
            if (j != i)
                cout << "*";
        }
        cout << endl;
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
            if (j != i)
                cout << "*";
        }
        cout << endl;
    }
}

void pattern_5_2(int n)
{
    cout << "*" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                cout << "* ";
            cout << j << " ";
        }
        for (int j = i - 1; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << "*" << endl;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                cout << "* ";
            cout << j << " ";
        }
        for (int j = i - 1; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << "*" << endl;
    }
    cout << "*";
}

void pattern_6(int n)
{
    vector<int> prev, curr;
    prev.push_back(1);
    prev.push_back(1);

    cout << 1 << endl;
    cout << 1 << " " << 1 << endl;

    for (int i = 3; i <= n; i++)
    {
        curr.clear();
        for (int j = 0; j < i; j++)
        {
            if (j == 0 || j == i - 1)
            {
                cout << 1 << " ";
                curr.push_back(1);
            }
            else
            {
                cout << prev[j - 1] + prev[j] << " ";
                curr.push_back(prev[j - 1] + prev[j]);
            }
        }
        prev = curr;
        cout << endl;
    }
}

void pattern_7(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        for (int j = n; j > 0; j--)
        {
            if (j > i)
                cout << "    ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        for (int j = 0; j < n; j++)
        {
            if (j < n - i)
                cout << "    ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

void pattern_8(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n || i + j == n + 1 || i == j)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_9(int n)
{
    n = n / 2 + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << "  ";
            else if (j == n - i + 1 || j == n || i == n)
                cout << "* ";
            else
                cout << "  ";
        }
        for (int j = 2; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= n - i)
                cout << "  ";
            else if (j == n - i + 1 || j == n || i == n)
                cout << "* ";
            else
                cout << "  ";
        }
        for (int j = 2; j <= i; j++)
        {
            if (j == 1 || j == i || i == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0)
            {
                if (j == 0 || j == n || j == n / 2)
                    cout << "  ";
                else
                    cout << "* ";
                continue;
            }
            if (i == 1)
            {
                if (j == 0 || j == n || j == n / 2)
                    cout << "* ";
                else
                    cout << "  ";
                continue;
            }
            if (i - j == 2 || i + j == 8)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

void pattern_11()
{
    for (int row = 0; row <= 2; row++)
    {
        for (int col = 0; col < 18; col++)
        {
            if ((col >= 2 - row && col <= row + 6) || (col >= 10 - row && col <= row + 14))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (int row = 0; row <= 8; row++)
    {
        for (int col = 0; col < 18; col++)
        {
            if (col >= row && col <= 16 - row)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Rectangle Patterns
    // pattern_1_1(5, 3);
    // pattern_1_2(5, 3);

    // Pyramid Patterns
    // pattern_2_1(5);
    // pattern_2_2(5);
    // pattern_2_3(5);
    // pattern_2_4(5);

    // Number Pyramid Patterns
    // pattern_3_1(5);
    // pattern_3_2(5);
    // pattern_3_3(5);

    // Palindrome Pyramid Patterns
    // pattern_4_1(5);
    // pattern_4_2(5);

    // Diamond Patterns
    // pattern_5_1(4);
    // pattern_5_2(3);

    // Pascal's Triangle
    // pattern_6(5);

    // Miscellaneous
    // pattern_7(5);
    // pattern_8(7);
    // pattern_9(9);
    // pattern_10();

    // Heart Shaped 10 by 17
    // pattern_11();

    return 0;
}