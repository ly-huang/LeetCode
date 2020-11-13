//
//  main.cpp
//  leetcode328
//
//  Created by ly on 2020/11/13.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(head==nullptr||head->next==nullptr)
        return head;
    ListNode *head2=head->next;
    ListNode *ptr1=head;
    ListNode *ptr2=head2;
    ListNode *ptr=ptr2->next;
    while(ptr!=nullptr)
    {
        ptr1->next=ptr;
        ptr1=ptr;
        ptr=ptr->next;
        ptr2->next=ptr;
        ptr2=ptr;
        if(ptr!=nullptr)
            ptr=ptr->next;
    }
    ptr1->next=head2;
    return head;
}

int main(int argc, const char * argv[]) {
    return 0;
}
