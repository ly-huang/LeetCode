//
//  main.cpp
//  leetcode143
//
//  Created by ly on 2020/10/20.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//void reorderList(ListNode* head) {
//    if(head==nullptr)
//        return;
//    stack<ListNode*> v;
//    ListNode *ptr=head;
//    while(ptr!=nullptr)
//    {
//        v.emplace(ptr);
//        ptr=ptr->next;
//    }
//    ptr=head;
//    ListNode *next=ptr->next;
//    ListNode *top=v.top();
//    while(true)
//    {
//        if(next==top)
//        {
//            next->next=nullptr;
//            break;
//        }
//        if(ptr==top)
//        {
//            ptr->next=nullptr;
//            break;
//        }
//        ptr->next=top;
//        v.pop();
//        ptr->next->next=next;
//        ptr=next;
//        top=v.top();
//        next=ptr->next;
//    }
//}

ListNode* reversal(ListNode* head)
{
    if(head==nullptr)
        return nullptr;
    ListNode*ptr=head;
    ListNode*last=nullptr;
    ListNode*next=ptr->next;
    while(ptr!=nullptr)
    {
        next=ptr->next;
        ptr->next=last;
        last=ptr;
        ptr=next;
    }
    return last;
}

void reorderList(ListNode* head) {
    if(head==nullptr)
        return;
    ListNode*ptr1=head;
    ListNode*ptr2=head;
    while(ptr2!=nullptr)
    {
        ptr2=ptr2->next;
        if(ptr2==nullptr)
            break;
        ptr2=ptr2->next;
        if(ptr2==nullptr)
            break;
        ptr1=ptr1->next;
    }
    ptr2=ptr1;
    ptr1=ptr1->next;
    ptr2->next=nullptr;
    ptr2=reversal(ptr1);
    ptr1=head;
    ListNode*next;
    while(ptr1!=nullptr&&ptr2!=nullptr)
    {
        next=ptr1->next;
        ptr1->next=ptr2;
        ptr2=ptr2->next;
        if(next!=ptr1->next)
            ptr1->next->next=next;
        else
            ptr1->next->next=nullptr;
        ptr1=next;
    }
    
}


int main(int argc, const char * argv[]) {
    ListNode *head=new ListNode(1);
    ListNode *ptr=head;
    for(int i=2;i<5;i++)
    {
        ptr->next=new ListNode(i);
        ptr=ptr->next;
    }
    reorderList(head);
    ptr=head;
    while(ptr!=nullptr)
    {
        cout<<ptr->val<<"->";
        ptr=ptr->next;
    }
    cout<<endl;
    return 0;
}
