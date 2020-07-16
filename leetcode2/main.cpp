#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *result=NULL;
    ListNode*ptr1=l1->next;
    ListNode*ptr2=l2->next;
    int temp=l1->val+l2->val;
    result=new ListNode(temp%10);
    int add=temp/10;
    ListNode*ptr=result;
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        temp=ptr1->val+ptr2->val+add;
        ptr->next=new ListNode(temp%10);
        add=temp/10;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
    while(ptr1!=NULL)
    {
        temp=ptr1->val+add;
        ptr->next=new ListNode(temp%10);
        add=temp/10;
        ptr1=ptr1->next;
        ptr=ptr->next;
    }

    while(ptr2!=NULL)
    {
        temp=ptr2->val+add;
        ptr->next=new ListNode(temp%10);
        add=temp/10;
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
    if(add!=0)
        ptr->next=new ListNode(add);
    return result;
}


int main() {
    ListNode *l1=new ListNode(4);
    l1->next=new ListNode(4);
    l1->next->next=new ListNode(5);

    ListNode *l2=new ListNode(5);
    l2->next=new ListNode(6);
    l2->next->next=new ListNode(4);
    ListNode*result=addTwoNumbers(l1,l2);
    ListNode *ptr= NULL;
    for(ptr=result;ptr!= NULL;ptr=ptr->next)
        cout<<ptr->val<<endl;
    return 0;
}