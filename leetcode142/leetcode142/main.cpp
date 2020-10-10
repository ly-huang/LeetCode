//
//  main.cpp
//  leetcode142
//
//  Created by ly on 2020/10/10.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    ListNode *ptr1=head;
    ListNode *ptr2=head;
    while(ptr2!=nullptr)
    {
        ptr2=ptr2->next;
        if(ptr2==nullptr)
            return nullptr;
        ptr2=ptr2->next;
        ptr1=ptr1->next;
        if(ptr1==ptr2)
        {
            ptr2=head;
            while(ptr1!=ptr2)
            {
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            return ptr1;
        }
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
