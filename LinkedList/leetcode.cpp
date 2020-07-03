#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
    }
};

ListNode *mid(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }

    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *midNode = mid(head);
    ListNode *rev = reverse(midNode);

    while (rev != nullptr)
    {
        if (head->val != rev->val)
            return false;

        head = head->next;
        rev = rev->next;
    }
    return true;
}

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow;

    ListNode *nHead = mid->next;
    mid->next = nullptr;
    nHead = reverse(nHead);

    while (head != nullptr && nHead != nullptr)
    {
        ListNode *fwd1 = head->next;
        ListNode *fwd2 = nHead->next;

        head->next = nHead;
        nHead->next = fwd1;

        head = fwd1;
        nHead = fwd2;
    }
}

ListNode* reverseKGroup(ListNode *head, int k) {
    ListNode *node = head;
    int count = 0;

    while(count < k) {
        if(node == nullptr) return head;
        node = node->next;
        count++;
    }

    ListNode* pre = reverseKGroup(node, k);
    while (count > 0) {  
        ListNode* next = head->next;
        head->next = pre; 
        pre = head; 
        head = next;
        count--;
    }
    return pre;
}

int main()
{
    return 0;
}