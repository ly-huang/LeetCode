//
//  main.cpp
//  leetcode234
//
//  Created by ly on 2020/10/23.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

bool isPalindrome(ListNode* head) {
    if(head==nullptr)
         return true;
     ListNode*ptr1=head;
     ListNode*ptr2=head;
     while(ptr2->next!=nullptr&&ptr2->next->next!=nullptr)
     {
         ptr2=ptr2->next->next;
         ptr1=ptr1->next;
     }
     ptr2=reversal(ptr1->next);
     ptr1=head;
    ListNode *temp=ptr2;
    bool result=true;
    while(ptr2!=nullptr)
    {
        if(ptr1->val!=ptr2->val)
        {
            result=false;
            break;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    temp=reversal(temp);
    return result;
}

int main(int argc, const char * argv[]) {
    int data[]={1,2,3,2,1};
    ListNode *head=new ListNode(1);
    ListNode *ptr=head;
    for(int i=1;i<5;i++)
    {
        ptr->next=new ListNode(data[i]);
        ptr=ptr->next;
    }
    cout<<isPalindrome(head)<<endl;
    return 0;
}
