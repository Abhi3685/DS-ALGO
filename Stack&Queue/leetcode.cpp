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

// =============== Leetcode 735 ===============
vector<int> leet735(vector<int> &asteroids)
{
    if (asteroids.size() == 0)
        return vector<int>();

    stack<int> st;
    for (int ele : asteroids)
    {
        if (ele > 0)
            st.push(ele);
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < -ele)
            {
                st.pop();
            }
            if (!st.empty() && st.top() == -ele)
                st.pop();
            else if (st.empty() || st.top() < 0)
                st.push(ele);
        }
    }

    asteroids.clear();
    while (!st.empty())
    {
        asteroids.push_back(st.top());
        st.pop();
    }
    reverse(asteroids.begin(), asteroids.end());
    return asteroids;
}

// =============== Leetcode 503 ===============
vector<int> leet503(vector<int> &nums)
{
    vector<int> res(nums.size(), -1);
    stack<int> s;

    // First Traversal: Same as next greater
    for (int i = 0; i < nums.size(); ++i)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            res[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    // 2nd Traversal: Resolving elements left in Stack
    for (int i = 0; i < nums.size(); ++i)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            res[s.top()] = nums[i];
            s.pop();
        }
    }

    return res;
}

// =============== Leetcode 42 ===============
int leet42(vector<int> &height)
{
    int ans = 0, n = height.size();
    if (n == 0)
        return 0;

    int left[n], right[n];

    // Left greatest calculation
    left[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], height[i]);
    }

    // Right greatest calculation
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], height[i]);
    }

    // water += min(lh, rh) - curr_height
    for (int i = 0; i < n; i++)
    {
        int lh = left[i], rh = right[i];
        int minh = min(lh, rh);
        ans += minh - height[i];
    }

    return ans;
}

// =============== Leetcode 901 ===============
class leet901
{
public:
    stack<pair<int, int>> st;

    int next(int price)
    {
        int val = 1;
        while (!st.empty() && st.top().first <= price)
        {
            val += st.top().second;
            st.pop();
        }
        st.push({price, val});
        return val;
    }
};

int main()
{
    // cout << leet20("[]{}()") << endl;

    // cout << leet1021("(()())(())") << endl;

    // cout << leet32(")()())") << endl;

    // vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << leet84(heights) << endl;

    // vector<int> asteroids = {5, 10, -5};
    // leet735(asteroids);
    // for (int n : asteroids)
    //     cout << n << " ";
    // cout << endl;

    // vector<int> nums = {1, 2, 1};
    // vector<int> ans = leet503(nums);
    // for (int n : ans)
    //     cout << n << " ";
    // cout << endl;

    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // cout << leet42(height) << endl;

    // leet901 S;
    // cout << S.next(100) << " ";
    // cout << S.next(80) << " ";
    // cout << S.next(60) << " ";
    // cout << S.next(70) << " ";
    // cout << S.next(60) << " ";
    // cout << S.next(75) << " ";
    // cout << S.next(85) << " ";
    // cout << endl;

    return 0;
}