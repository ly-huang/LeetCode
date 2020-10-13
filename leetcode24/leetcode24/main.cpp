//
//  main.cpp
//  leetcode24
//
//  Created by ly on 2020/10/13.
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

ListNode* swapPairs(ListNode* head) {
    if(head==nullptr)
        return nullptr;
    ListNode*ptr=head;
    ListNode*next=nullptr;
    if(head->next!=nullptr)
        head=head->next;
    ListNode *last=nullptr;
    while(ptr!=nullptr)
    {
        next=ptr->next;
        if(next!=nullptr)
        {
            ptr->next=next->next;
            next->next=ptr;
            if(last!=nullptr)
                last->next=next;
            last=ptr;
            ptr=ptr->next;
            continue;
        }
        break;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    swapPairs(head);
    return 0;
}
