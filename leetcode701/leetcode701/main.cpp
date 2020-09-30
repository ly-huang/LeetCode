//
//  main.cpp
//  leetcode701
//
//  Created by ly on 2020/9/30.
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root==nullptr)
    {
        root=new TreeNode(val);
        return root;
    }
    TreeNode *node=root;
    while(node!=nullptr)
    {
        if(node->val>val)
        {
            if(node->left==nullptr)
            {
                node->left=new TreeNode(val);
                return root;
            }
            node=node->left;
        }
        else
        {
            if(node->right==nullptr)
            {
                node->right=new TreeNode(val);
                return root;
            }
            node=node->right;
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
