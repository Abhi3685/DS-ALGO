#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyQueue
{
    stack<int> s1, s2;

public:
    void enqueue(int data)
    {
        s1.push(data);
    }

    int dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty";
            return 0;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    bool empty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }
        return false;
    }
};

class MyStack
{
public:
    queue<int> q1, q2;

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();
        q1.pop();
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return top;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

int main()
{
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    return 0;
}