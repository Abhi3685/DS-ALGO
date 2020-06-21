#include <iostream>
#include <vector>
using namespace std;

class Stack
{
    vector<int> arr;
    int size = 0;
    int top = -1;

public:
    // Constructors
    Stack()
    {
        arr.resize(5);
    }

    Stack(int size)
    {
        arr.resize(size);
    }

    // Push
    void push(int val)
    {
        if (top == arr.size() - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
        size++;
    }

    // Pop
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int rval = arr[top--];
        size--;
        return rval;
    }

    // Top
    int peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }

    // isEmpty
    bool isEmpty()
    {
        return size == 0;
    }

    // Display
    void display()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
            return;
        }
        for (int n : arr)
            cout << n << " ";
        cout << endl;
    }
};

int main()
{
    Stack st(2);
    st.push(10);
    st.push(20);
    // st.push(30); // Uncomment this line to see stackoverflow error
    st.pop();
    st.pop();
    st.pop();
    cout << "Top: " << st.peek() << endl;
    st.display();
    return 0;
}