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

bool canPartitionUtility(vector<int> &arr, int idx, int k, int sum, int target, vector<bool> &vis)
{
    if (k == 1)
        return true;
    if (sum > target)
        return false;
    if (sum == target)
        return canPartitionUtility(arr, 0, k - 1, 0, target, vis);

    for (int i = idx; i < arr.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            if (canPartitionUtility(arr, i + 1, k, sum + arr[i], target, vis))
                return true;
            vis[i] = false;
        }
    }
    return false;
}

bool canPartition(vector<int> &arr, int k)
{
    int sum = 0;
    for (int num : arr)
        sum += num;
    if (sum % k != 0)
    {
        cout << "Not Possible!" << endl;
        return false;
    }

    vector<bool> vis(arr.size());
    bool res = canPartitionUtility(arr, 0, k, 0, sum / k, vis);
    if (res)
        cout << "Possible!" << endl;
    else
        cout << "Not Possible!" << endl;
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

    // Partition of a set into K subsets with equal sum
    // https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
    vector<int> arr = {2, 1, 4, 5, 6};
    int k = 3;
    canPartition(arr, k);
}

int main()
{
    solve();
    return 0;
}