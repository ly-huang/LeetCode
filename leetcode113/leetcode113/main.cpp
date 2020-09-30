//
//  main.cpp
//  leetcode113
//
//  Created by ly on 2020/9/30.
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

void getResult(TreeNode* &node,vector<vector<int>> &result,vector<int> &current,const int &sum)
{
    int val=sum-node->val;
    current.emplace_back(node->val);
    if(val==0)
    {
        if(node->left==nullptr&&node->right==nullptr)
        {
            result.emplace_back(current);
            current.pop_back();
            return;
        }
    }
    TreeNode* next=node->left;
    if(next!=nullptr)
        getResult(next, result, current, val);
    next=node->right;
    if(next!=nullptr)
        getResult(next, result, current, val);
    current.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(root==nullptr)
        return {};
    vector<vector<int>> result;
    vector<int> current;
    getResult(root, result, current, sum);
    return result;
}

int main(int argc, const char * argv[]) {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    pathSum(root, 1);
    return 0;
}
