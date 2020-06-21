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

class Queue
{
    vector<int> arr;
    int size = 0;
    int front = 0;
    int end = -1;

public:
    // Constructors
    Queue()
    {
        arr.resize(10);
    }
    Queue(int size)
    {
        arr.resize(size);
    }

    // Push
    void push(int val)
    {
        if (size == arr.size())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        end = (end + 1) % arr.size();
        arr[end] = val;
        size++;
    }

    // Pop
    int pop()
    {
        if (size == 0)
            return -1;
        arr[front] = 0;
        front = (front + 1) % arr.size();
        size--;
    }

    // Top
    int peek()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    // isEmpty
    bool isEmpty()
    {
        return size == 0;
    }

    // Display
    void display()
    {
        if (size == 0)
        {
            cout << "Queue Empty" << endl;
            return;
        }

        for (int i = front; i != end; i = (i + 1) % arr.size())
            cout << arr[i] << " ";
        cout << arr[end] << endl;
    }
};

int main()
{
    //////////////////////////////////////////////////////////////
    //////////////////////////// STACK ///////////////////////////
    //////////////////////////////////////////////////////////////
    Stack st(2);
    st.push(10);
    st.push(20);
    // st.push(30); // Uncomment this line to see stackoverflow error
    st.pop();
    st.pop();
    st.pop();
    cout << "Top: " << st.peek() << endl;
    st.display();

    //////////////////////////////////////////////////////////////
    //////////////////////////// QUEUE ///////////////////////////
    //////////////////////////////////////////////////////////////
    Queue qu(4);
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    qu.push(50);
    cout << "Top: " << qu.peek() << endl;
    qu.display();

    return 0;
}