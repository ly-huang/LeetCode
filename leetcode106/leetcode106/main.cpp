//
//  main.cpp
//  leetcode106
//
//  Created by ly on 2020/9/25.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* getResult(vector<int>& inorder,vector<int>& postorder,const int &index,const int &left ,const int &right)
{
    if(left>right)
        return nullptr;
    else if(left==right)
        return new TreeNode(inorder[left]);
    int val=postorder[index];
    TreeNode* node=new TreeNode(val);
    int i=left;
    while(inorder[i]!=val)
        i++;
    int n=right-i;
    node->left=getResult(inorder, postorder, index-n-1, left, i-1);
    node->right=getResult(inorder, postorder, index-1, i+1, right);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()||postorder.empty())
        return nullptr;
    int n=int(inorder.size());
    TreeNode *root=getResult(inorder, postorder, n-1, 0, n-1);
    return root;
}

int main(int argc, const char * argv[]) {
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
    auto result=buildTree(inorder, postorder);
    queue<TreeNode*> q;
    q.emplace(result);
    TreeNode *ptr;
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        cout<<ptr->val<<" ";
        if(ptr->left!=nullptr)
            q.emplace(ptr->left);
        if(ptr->right!=nullptr)
            q.emplace(ptr->right);
    }
    
    std::cout << "\n";
    return 0;
}
