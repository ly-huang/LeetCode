//
//  main.cpp
//  leetcode129
//
//  Created by ly on 2020/10/29.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getResult(TreeNode *&node,int current,int &result)
{
    current=current*10+node->val;
    if(node->left==nullptr&&node->right==nullptr)
    {
        result+=current;
        return;
    }
    if(node->left!=nullptr)
        getResult(node->left, current, result);
    if(node->right!=nullptr)
        getResult(node->right, current, result);
}

int sumNumbers(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int result=0;
    getResult(root, 0, result);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
