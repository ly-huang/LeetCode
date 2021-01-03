//
//  main.cpp
//  leetcode86
//
//  Created by ly on 2021/1/3.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if(head==nullptr)
        return nullptr;
    ListNode head1(-1);
    ListNode head2(-1);
    ListNode *ptr1=&head1;
    ListNode *ptr2=&head2;
    ListNode *ptr=head;
    while(ptr!=nullptr)
    {
        if(ptr->val<x)
        {
            ptr1->next=ptr;
            ptr1=ptr;
        }
        else
        {
            ptr2->next=ptr;
            ptr2=ptr;
        }
        ptr=ptr->next;
    }
    ptr1->next=head2.next;
    ptr2->next=nullptr;
    return head1.next;
}

int main(int argc, const char * argv[]) {
    ListNode *head=new ListNode(1);
    ListNode *ptr=head;
    int data[]={1,4,3,2,5,2};
    for(int i=1;i<6;i++)
    {
        ptr->next=new ListNode(data[i]);
        ptr=ptr->next;
    }
    auto result=partition(head, 3);
    ptr=result;
    while(ptr!=nullptr)
    {
        cout<<ptr->val<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}
