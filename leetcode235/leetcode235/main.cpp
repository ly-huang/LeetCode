//
//  main.cpp
//  leetcode235
//
//  Created by ly on 2020/9/27.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *getResult(TreeNode *&node,TreeNode *&p,TreeNode *&q)
{
    if(node->val>=q->val&&node->val<=p->val)
        return node;
    if(node->val>p->val)
        return getResult(node->left, p, q);
    else
        return getResult(node->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr||p==nullptr||q==nullptr)
        return nullptr;
    if(p->val>q->val)
        return getResult(root, p, q);
    else
        return getResult(root, q, p);
}

int main(int argc, const char * argv[]) {
    return 0;
}
