#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void nextGreaterOnRight()
{
    vector<int> arr = {1, 3, 2, 4, 8, 6, 5, 9, 1};
    vector<int> nextGreater(arr.size(), -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[st.top()])
        {
            while (!st.empty() && arr[i] > arr[st.top()])
            {
                int rElement = st.top();
                st.pop();
                nextGreater[rElement] = arr[i];
            }
        }
        st.push(i);
    }
    for (int n : nextGreater)
        cout << n << " ";
    cout << endl;
}

void nextGreaterOnLeft()
{
    vector<int> arr = {1, 3, 2, 4, 8, 6, 5, 9, 1};
    vector<int> nextGreater(arr.size(), -1);
    stack<int> st;
    st.push(arr.size() - 1);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > arr[st.top()])
        {
            while (!st.empty() && arr[i] > arr[st.top()])
            {
                int rElement = st.top();
                st.pop();
                nextGreater[rElement] = arr[i];
            }
        }
        st.push(i);
    }
    for (int n : nextGreater)
        cout << n << " ";
    cout << endl;
}

void nextSmallerOnRight()
{
    vector<int> arr = {1, 3, 2, 4, 8, 6, 5, 9, 1};
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
                nextSmaller[rElement] = arr[i];
            }
        }
        st.push(i);
    }
    for (int n : nextSmaller)
        cout << n << " ";
    cout << endl;
}

void nextSmallerOnLeft()
{
    vector<int> arr = {1, 3, 2, 4, 8, 6, 5, 9, 1};
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
                nextSmaller[rElement] = arr[i];
            }
        }
        st.push(i);
    }
    for (int n : nextSmaller)
        cout << n << " ";
    cout << endl;
}

int main()
{
    nextGreaterOnRight();
    nextGreaterOnLeft();

    nextSmallerOnRight();
    nextSmallerOnLeft();

    return 0;
}