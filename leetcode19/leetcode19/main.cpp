//
//  main.cpp
//  leetcode19
//
//  Created by ly on 2020/10/18.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode temp;
    temp.next=head;
    ListNode *ptr1=head;
    ListNode *ptr2=&temp;
    for(int i=0;i<n&&ptr1!=nullptr;i++)
    {
        ptr1=ptr1->next;
    }
    while(ptr1!=nullptr)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1=ptr2->next;
    ptr2->next=ptr1->next;
    delete ptr1;
    return temp.next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
