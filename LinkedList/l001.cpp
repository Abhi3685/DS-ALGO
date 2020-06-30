#include <iostream>
#include <list>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};

void display(list<int> ll)
{
    for (auto it = ll.begin(); it != ll.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void getMid(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data << endl;
}

int main()
{
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    display(ll);

    return 0;
}