//
//  main.cpp
//  leetcode145
//
//  Created by ly on 2020/9/29.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<int> result;
    stack<TreeNode*>s;
    TreeNode* node=root;
    TreeNode* top=nullptr;
    bool next=true;
    while(next)
    {
        if(node->left!=nullptr)
        {
            s.emplace(node);
            node=node->left;
            continue;
        }
        if(node->right!=nullptr)
        {
            s.emplace(node);
            node=node->right;
            continue;
        }
        result.emplace_back(node->val);
        next=false;
        while(!s.empty())
        {
            top=s.top();
            if(top->right==node)
            {
                result.emplace_back(top->val);
                s.pop();
                node=top;
            }
            else
            {
                if(top->right!=nullptr)
                {
                    node=top->right;
                    next=true;
                    break;
                }
                else
                {
                    result.emplace_back(top->val);
                    s.pop();
                    node=top;
                }
                             
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
