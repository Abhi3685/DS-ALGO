#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

// =============== Leetcode 84 ===============
vector<int> nextSmallerOnRight(vector<int> &arr)
{
    vector<int> nextSmaller(arr.size(), -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[st.top()])
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                int rElement = st.top();
                st.pop();
                nextSmaller[rElement] = i;
            }
        }
        st.push(i);
    }
    return nextSmaller;
}

vector<int> nextSmallerOnLeft(vector<int> &arr)
{
    vector<int> nextSmaller(arr.size(), -1);
    stack<int> st;
    st.push(arr.size() - 1);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[st.top()])
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                int rElement = st.top();
                st.pop();
                nextSmaller[rElement] = i;
            }
        }
        st.push(i);
    }
    return nextSmaller;
}

int leet84(vector<int> &heights)
{
    vector<int> rs = nextSmallerOnRight(heights);
    vector<int> ls = nextSmallerOnLeft(heights);

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int h = heights[i];
        int w = rs[i] - ls[i] - 1;
        int area = h * w;
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    // cout << leet20("[]{}()") << endl;

    // cout << leet1021("(()())(())") << endl;

    // cout << leet32(")()())") << endl;

    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << leet84(heights) << endl;

    return 0;
}