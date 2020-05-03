#include <iostream>
#include <vector>
using namespace std;

string str1 = "send";
string str2 = "more";
string str3 = "money";

int getNumberFromString(string num, vector<int> &map)
{
    int res = 0;
    for (int i = 0; i < num.size(); i++)
    {
        res = res * 10 + map[num[i] - 'a'];
    }
    return res;
}

void crypto(string str, int idx, vector<int> &map, int vis)
{
    if (idx == str.size())
    {
        int n1 = getNumberFromString(str1, map);
        int n2 = getNumberFromString(str2, map);
        int n3 = getNumberFromString(str3, map);
        if ((n1 + n2) == n3)
        {
            cout << n1 << " + " << n2 << " = " << n3 << endl;
        }
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        int mask = 1 << i;
        if ((vis & mask) == 0)
        {
            vis ^= mask;
            map[str[idx] - 'a'] = i;
            crypto(str, idx + 1, map, vis);
            vis ^= mask;
            map[str[idx] - 'a'] = -1;
        }
    }
}

void crypto_01(string str, int idx, vector<int> &map, int vis)
{
    if (idx == str.length())
    {
        if (map[str1[0] - 'a'] == 0 || map[str2[0] - 'a'] == 0 || map[str3[0] - 'a'] == 0)
        {
            return;
        }
        int n1 = getNumberFromString(str1, map);
        int n2 = getNumberFromString(str2, map);
        int n3 = getNumberFromString(str3, map);
        if ((n1 + n2) == n3)
        {
            cout << n1 << " + " << n2 << " = " << n3 << endl;
        }
        return;
    }

    for (int i = 0; i <= 9; i++)
    {
        int mask = 1 << i;
        if ((vis & mask) == 0)
        {
            vis ^= mask;
            map[str[idx] - 'a'] = i;
            crypto_01(str, idx + 1, map, vis);
            vis ^= mask;
            map[str[idx] - 'a'] = -1;
        }
    }
}

void perOfString(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        string s = str.substr(0, i) + str.substr(i + 1);
        perOfString(s, ans + str[i]);
    }
}

void equiSet(vector<int> &arr, int idx, int sum1, int sum2, string set1, string set2)
{
    if (idx == arr.size())
    {
        if (sum1 == sum2)
        {
            cout << set1 << " = " << set2 << endl;
        }
        return;
    }
    equiSet(arr, idx + 1, sum1 + arr[idx], sum2, set1 + to_string(arr[idx]) + " ", set2);
    equiSet(arr, idx + 1, sum1, sum2 + arr[idx], set1, set2 + to_string(arr[idx]) + " ");
}

void solve()
{
    // Cryptoarithmetic Problem (Recursion)
    // string str = str1 + str2 + str3;
    // vector<int> freq(26, 0);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     freq[str[i] - 'a']++;
    // }
    // str = "";
    // for (int i = 0; i < freq.size(); i++)
    // {
    //     if (freq[i] != 0)
    //         str += (char)(i + 'a');
    // }
    // vector<int> map(26, -1);
    // int vis = 0;
    // crypto(str, 0, map, vis);

    // Cryptoarithmetic Problem
    // Restrict first letter of assignment to digit other than 0
    // crypto_01(str, 0, map, vis);

    // Permutation of String
    // Example: abc -> abc, acb, bac, bca, cab, cba
    // perOfString("abc", "");

    // Q) Given an array of numbers A = [10, 20, 30, ..., 80]. Divide the array into
    // 2 sets that satisfies the following constraints
    //      1. SUMMATION set1 = SUMMATION set2
    //      2. set1 UNION set2 = A
    //      3. set1 INTERSECTION set2 = PHI(EMPTY SET)
    // vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    // equiSet(arr, 1, arr[0], 0, to_string(arr[0]) + " ", "");
}

int main()
{
    solve();
    return 0;
}