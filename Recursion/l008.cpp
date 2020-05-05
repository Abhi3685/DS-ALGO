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

string ans;
int min_ = (int)1e8;
void tugOfWar(vector<int> &arr, int idx, int sum1, int sum2, string set1, string set2)
{
    if (idx == (int)arr.size())
    {
        if (abs(sum1 - sum2) <= min_)
        {
            min_ = abs(sum1 - sum2);
            ans = "[" + set1.substr(0, set1.size() - 2) + "][" + set2.substr(0, set2.size() - 2) + "]";
        }
        return;
    }
    if (idx >= (int)arr.size())
        return;
    tugOfWar(arr, idx + 1, sum1 + arr[idx], sum2, set1 + to_string(arr[idx]) + ", ", set2);
    tugOfWar(arr, idx + 1, sum1, sum2 + arr[idx], set1, set2 + to_string(arr[idx]) + ", ");
}

int main()
{
    string s = "226";
    cout << numDecodings(s, 0);

    vector<int> arr = {2, 3, 4, 5, 6, 7};
    tugOfWar(arr, 1, arr[0], 0, to_string(arr[0]) + ", ", "");
    cout << ans;

    return 0;
}