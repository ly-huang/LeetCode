//
//  main.cpp
//  leetcode530
//
//  Created by ly on 2020/10/12.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getResult(TreeNode *node,int &last,int &result)
{
    if(node->left!=nullptr)
        getResult(node->left, last, result);
    if(last==-1)
    {
        last=node->val;
    }
    else
    {
        int val=node->val;
        if(val-last<result)
            result=val-last;
        last=val;
    }
    if(node->right!=nullptr)
        getResult(node->right, last, result);
}

int getMinimumDifference(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int last=-1;
    int result=INT_MAX;
    getResult(root, last, result);
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
