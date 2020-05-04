#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict, unordered_map<string, bool> &map)
{
    if (s.size() == 0)
    {
        return map[s] = true;
    }

    if (map.find(s) != map.end())
        return map[s];

    bool res = false;
    for (int i = 1; i <= s.size(); i++)
    {
        string str = s.substr(0, i);
        if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end())
            res = res || wordBreak(s.substr(i), wordDict, map);
    }
    return map[s] = res;
}

int main()
{
    // WordBreak
    unordered_map<string, bool> map;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict, map);
    return 0;
}