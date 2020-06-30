#include <iostream>
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

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

public:
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ///////////////// Add Node //////////////////
    void addFirst(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = tail = node;
            size++;
            return;
        }

        node->next = head;
        head = node;
        size++;
    }

    void addLast(int data)
    {
        Node *node = new Node(data);
        if (size == 0)
        {
            head = tail = node;
            size++;
            return;
        }

        tail->next = node;
        tail = node;
        size++;
    }

    void addAt(int data, int idx)
    {
        Node *node = new Node(data);
        Node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
        size++;
    }

    ///////////////// Get Node //////////////////
    Node *getFirst()
    {
        return head;
    }

    Node *getLast()
    {
        return tail;
    }

    Node *getAt(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    ///////////////// Remove Node //////////////////
    void removeFirst()
    {
        head = head->next;
        size--;
        if (isEmpty())
        {
            head = tail = nullptr;
        }
    }

    void removeLast()
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        size--;
        if (isEmpty())
        {
            head = tail = nullptr;
        }
    }

    void removeAt(int idx)
    {
        Node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
        if (isEmpty())
        {
            head = tail = nullptr;
        }
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.addLast(2);
    ll.addLast(3);
    ll.addLast(5);
    ll.addFirst(1);
    ll.addAt(4, 3);
    ll.display();
    // cout << ll.getFirst()->data << endl;
    // cout << ll.getLast()->data << endl;
    // cout << ll.getAt(3)->data << endl;
    // ll.removeFirst();
    // ll.removeLast();
    // ll.removeAt(2);
    // ll.display();
    return 0;
}