//
//  main.cpp
//  leetcode501
//
//  Created by ly on 2020/9/24.
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

void getResult(TreeNode *node,vector<int> &result,TreeNode *&last,int &cur_count,int &count)
{
    if(node->left!=nullptr)
        getResult(node->left,result,last,cur_count,count);
    if(last==nullptr)
    {
        last=node;
    }
    else if(last!=nullptr&&last->val==node->val)
        cur_count++;
    else
    {
        if(cur_count==count)
            result.emplace_back(last->val);
        else if(cur_count>count)
        {
            result.clear();
            result.emplace_back(last->val);
            count=cur_count;
        }
        cur_count=1;
        last=node;
    }
    if(node->right!=nullptr)
        getResult(node->right,result,last,cur_count,count);
}

vector<int> findMode(TreeNode* root) {
    if(root==nullptr)
        return {};
    vector<int> result;
    TreeNode *last=nullptr;
    int cur_count=1;
    int count=1;
    getResult(root,result,last,cur_count,count);
    if(cur_count==count)
        result.emplace_back(last->val);
    else if(cur_count>count)
    {
        result.clear();
        result.emplace_back(last->val);
        count=cur_count;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
