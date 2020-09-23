//
//  main.cpp
//  leetcode617
//
//  Created by ly on 2020/9/23.
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1==nullptr)
        return t2;
    if(t2==nullptr)
        return t1;
    queue<TreeNode*> q;
    q.emplace(t1);
    q.emplace(t2);
    TreeNode *node1,*node2;
    while(!q.empty())
    {
        node1=q.front();
        q.pop();
        node2=q.front();
        q.pop();
        node1->val+=node2->val;
        if(node1->left!=nullptr&&node2->left!=nullptr)
        {
            q.emplace(node1->left);
            q.emplace(node2->left);
        }
        else if(node1->left==nullptr)
        {
            node1->left=node2->left;
        }
        if(node1->right!=nullptr&&node2->right!=nullptr)
        {
            q.emplace(node1->right);
            q.emplace(node2->right);
        }
        else if(node1->right==nullptr)
        {
            node1->right=node2->right;
        }
    }
    return t1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
