//
//  main.cpp
//  leetcode109
//
//  Created by ly on 2020/8/18.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//用向量存储
//TreeNode* createTreeByVector(const vector<int>&data,int left,int right)
//{
//    if(left>right)
//        return nullptr;
//    int mid=left+((right-left)>>1);
//    TreeNode* result=new TreeNode(data[mid]);
//    result->left=createTreeByVector(data, left, mid-1);
//    result->right=createTreeByVector(data, mid+1, right);
//    return result;
//}
//
//TreeNode* sortedListToBST(ListNode* head) {
//    if(head==nullptr)
//        return nullptr;
//    vector<int> data;
//    for(auto ptr=head;ptr!=nullptr;ptr=ptr->next)
//    {
//        data.push_back(ptr->val);
//    }
//    TreeNode* result=createTreeByVector(data, 0, data.size()-1);
//    return result;
//}


//直接递归找中间节点
TreeNode* createTree(ListNode*& head,int left,int right)
{
    if(left>right)
        return nullptr;
    int mid=left+((right-left)>>1);
    TreeNode* result=new TreeNode();
    result->left=createTree(head, left, mid-1);
    result->val=head->val;
    head=head->next;
    result->right=createTree(head, mid+1, right);
    return result;
}

TreeNode* sortedListToBST(ListNode* head) {
    if(head==nullptr)
        return nullptr;
    int size=0;
    for(auto ptr=head;ptr!=nullptr;ptr=ptr->next)
    {
        size++;
    }
    TreeNode* result=createTree(head, 0, size-1);
    return result;
}

int main(int argc, const char * argv[]) {
    ListNode* head=new ListNode(-10);
    head->next=new ListNode(-3);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(5);
    head->next->next->next->next=new ListNode(9);
    auto result=sortedListToBST(head);
    return 0;
}
