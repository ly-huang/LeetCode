//
//  main.cpp
//  leetcode141
//
//  Created by ly on 2020/10/9.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if(head==nullptr)
        return false;
    ListNode* ptr1=head;
    ListNode* ptr2=head;
    while(ptr2!=nullptr)
    {
        ptr2=ptr2->next;
        if(ptr2!=nullptr)
            ptr2=ptr2->next;
        else
            return false;
        ptr1=ptr1->next;
        if(ptr1==ptr2)
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
