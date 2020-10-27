//
//  main.cpp
//  leetcode144
//
//  Created by ly on 2020/10/27.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<int> result;
    stack<TreeNode*> s;
    s.emplace(root);
    TreeNode *ptr=nullptr;
    while(!s.empty())
    {
        ptr=s.top();
        s.pop();
        result.emplace_back(ptr->val);
        if(ptr->right!=nullptr)
            s.emplace(ptr->right);
        if(ptr->left!=nullptr)
            s.emplace(ptr->left);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
