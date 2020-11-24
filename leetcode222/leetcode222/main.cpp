//
//  main.cpp
//  leetcode222
//
//  Created by ly on 2020/11/24.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int left=countNodes(root->left);
    int right=countNodes(root->right);
    return 1+left+right;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
