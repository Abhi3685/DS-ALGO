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

bool canPHword(vector<vector<char>> &box, int r, int c, string word)
{
    if (r >= box.size() || c + word.length() - 1 >= box[0].size())
        return false;
    for (int j = 0; j < word.length(); j++)
    {
        if (box[r][c + j] != '-' && box[r][c + j] != word[j])
            return false;
    }
    return true;
}

bool canPVword(vector<vector<char>> &box, int r, int c, string word)
{
    if (r + word.length() - 1 >= box.size() || c >= box[0].size())
        return false;
    for (int j = 0; j < word.length(); j++)
    {
        if (box[r + j][c] != '-' && box[r + j][c] != word[j])
            return false;
    }
    return true;
}

vector<bool> PHword(vector<vector<char>> &box, int r, int c, string word)
{
    vector<bool> loc(word.length());
    for (int j = 0; j < word.length(); j++)
    {
        if (box[r][c + j] == '-')
        {
            box[r][c + j] = word[j];
            loc[j] = true;
        }
    }
    return loc;
}

void UnPHword(vector<vector<char>> &box, int r, int c, vector<bool> &loc)
{
    for (int j = 0; j < loc.size(); j++)
    {
        if (loc[j])
        {
            box[r][c + j] = '-';
        }
    }
}

vector<bool> PVword(vector<vector<char>> &box, int r, int c, string word)
{
    vector<bool> loc(word.length());
    for (int j = 0; j < word.length(); j++)
    {
        if (box[r + j][c] == '-')
        {
            box[r + j][c] = word[j];
            loc[j] = true;
        }
    }
    return loc;
}

void UnPVword(vector<vector<char>> &box, int r, int c, vector<bool> &loc)
{
    for (int j = 0; j < loc.size(); j++)
    {
        if (loc[j])
        {
            box[r + j][c] = '-';
        }
    }
}

void crossWord(vector<vector<char>> &box, vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (int i = 0; i < box.size(); i++)
        {
            for (int j = 0; j < box[0].size(); j++)
            {
                cout << box[i][j];
            }
            cout << endl;
        }
        return;
    }
    string word = words[idx];
    for (int i = 0; i < box.size(); i++)
    {
        for (int j = 0; j < box[0].size(); j++)
        {
            if (box[i][j] == '-' || box[i][j] == word[0])
            {
                if (canPHword(box, i, j, word))
                {
                    vector<bool> loc = PHword(box, i, j, word);
                    crossWord(box, words, idx + 1);
                    UnPHword(box, i, j, loc);
                }
                if (canPVword(box, i, j, word))
                {
                    vector<bool> loc = PVword(box, i, j, word);
                    crossWord(box, words, idx + 1);
                    UnPVword(box, i, j, loc);
                }
            }
        }
    }
}

int main()
{
    // WordBreak
    unordered_map<string, bool> map;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict, map);

    // CrossWord
    vector<vector<char>> box = {{'+', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
                                {'-', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
                                {'-', '-', '-', '-', '-', '-', '-', '+', '+', '-'},
                                {'-', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
                                {'-', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
                                {'-', '+', '+', '+', '+', '-', '-', '-', '-', '-'},
                                {'-', '-', '-', '-', '-', '-', '+', '+', '+', '-'},
                                {'-', '+', '+', '+', '+', '+', '+', '+', '+', '-'},
                                {'+', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                                {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};
    string str = "";
    vector<string> words = {"CHEMISTRY", "PHYSICS", "GEOGRAPHY", "HISTORY", "MATHS", "CIVICS"};
    crossWord(box, words, 0);

    return 0;
}