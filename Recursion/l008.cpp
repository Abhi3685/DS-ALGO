#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s, int idx)
{
    if (idx == s.size())
        return 1;

    char ch = s[idx];
    int count = 0;
    if (ch != '0')
        count += numDecodings(s, idx + 1);

    if (idx + 1 < s.size())
    {
        char ch2 = s[idx + 1];
        int val = (ch - '0') * 10 + (ch2 - '0');
        if (val >= 10 && val <= 26)
            count += numDecodings(s, idx + 2);
    }
    return count;
}

int main()
{
    string s = "226";
    cout << numDecodings(s, 0);
    return 0;
}