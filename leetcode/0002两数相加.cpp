#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} 
    ListNode(int x) : val(x), next(nullptr){} 
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
    int remainder = 0;
    ListNode *tmp = nullptr, *tail = nullptr;
    ListNode *head = new ListNode((remainder + l1->val + l2->val) % 10);
    tail = head;
    remainder = (remainder + l1->val + l2->val) / 10;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 || l2 || remainder){
        int l1val = 0, l2val = 0;
        if(l1)
        l1val = l1->val;
        if (l2)
        l2val = l2->val;
        tmp = new ListNode((remainder + l1val + l2val) % 10);
        remainder = (remainder + l1val + l2val) / 10;
        tail->next = tmp;
        tail = tmp;
        if(l1)
        l1 = l1->next;
        if (l2)
        l2 = l2->next;
    }
    return head;
}

int main(){
     int a[] = {9, 9, 9, 9, 9, 9, 9}, b[] = {9, 9, 9, 9};
    //int a[] = {3, 4, 2}, b[] = {4, 6, 5};
    ListNode *l1 = nullptr, *l2 = nullptr, *tmp = nullptr;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i){
        tmp = new ListNode;
        tmp->val = a[i];
        tmp->next = l1;
        l1 = tmp;
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i)
    {
        tmp = new ListNode;
        tmp->val = b[i];
        tmp->next = l2;
        l2 = tmp;
    }
    ListNode *output = addTwoNumbers(l1, l2);
    while (output != nullptr)
    {
        cout << output->val;
        output = output->next;
    }
    return 0;
}