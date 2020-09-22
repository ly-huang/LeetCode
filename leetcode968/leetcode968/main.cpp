//
//  main.cpp
//  leetcode968
//
//  Created by ly on 2020/9/22.
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

int dfs(TreeNode *node,int &result)
{
    //0：待覆盖
    //1：覆盖
    //2：安装摄像头
    int left=1;  //默认为左节点为空的情况，如果为空，则可以认为其是覆盖的
    int right=1; //默认为又节点为空的情况，如果为空，则可以认为其是覆盖的
    if(node->left!=nullptr)
        left=dfs(node->left,result);
    if(node->right!=nullptr)
        right=dfs(node->right,result);
    if(left==0||right==0)//左右节点中有一个节点没有被覆盖，则当前节点需要安装一个摄像头，以保障覆盖其左右节点
    {
        result++;
        return 2;
    }
    if(left==1&&right==1)//左右节点均已覆盖，则当前节点返回没有被覆盖（0）
        return 0;
    if(left+right>=3)//左右节点中有一个安装了摄像头，则该节点被覆盖
        return 1;
    return -1;
}

int minCameraCover(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int result=0;
    if(dfs(root,result)==0)//根节点还需要被覆盖
        result++;
    return result;
}

TreeNode* creatTree(vector<int> &data)
{
    TreeNode* root=new TreeNode(data[0]);
    queue<TreeNode**> q;
    q.emplace(&root);
    TreeNode **ptr;
    int index=1;
    int n=int(data.size());
    int left,right;
    while(!q.empty()&&index<n)
    {
        ptr=q.front();
        q.pop();
        left=data[index++];
        right=data[index++];
        if(left!=-1)
        {
            (*ptr)->left=new TreeNode(left);
            q.emplace(&((*ptr)->left));
        }
        if(right!=-1)
        {
            (*ptr)->right=new TreeNode(right);
            q.emplace(&((*ptr)->right));
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    vector<int> data={0,0,-1,0,-1,0,-1,-1,0};
    TreeNode *root=creatTree(data);
    auto result=minCameraCover(root);
    cout<<result<<endl;
    return 0;
}
