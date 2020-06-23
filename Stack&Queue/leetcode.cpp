#include <iostream>
#include <stack>
using namespace std;

// =============== Leetcode 20 ===============
bool leet20(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if (top == '(' && c != ')')
                return false;
            else if (top == '[' && c != ']')
                return false;
            else if (top == '{' && c != '}')
                return false;
        }
    }

    if (!st.empty())
        return false;
    return true;
}

// =============== Leetcode 1021 ===============
string leet1021(string S)
{
    stack<char> st;
    string ans = "";
    for (auto ch : S)
    {
        if (ch == ')')
            st.pop();
        if (!st.empty())
            ans += ch;
        if (ch == '(')
            st.push(ch);
    }
    return ans;
}

// =============== Leetcode 32 ===============
int leet32(string str)
{
    if (str.size() == 0)
        return 0;
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.top() != -1 && str[i] == ')' && str[st.top()] == '(')
        {
            st.pop();
            int len = i - st.top();
            if (ans < len)
                ans = len;
        }
        else
        {
            st.push(i);
        }
    }
    return ans;
}

int main()
{
    // cout << leet20("[]{}()") << endl;
    // cout << leet1021("(()())(())") << endl;
    // cout << leet32(")()())") << endl;

    return 0;
}