#include <iostream>
#include <stack>
using namespace std;
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int maxDepth(TreeNode* root) {
    if(root==NULL)
        return 0;
    stack<TreeNode *> sTreeNode;
    stack<int> sDepth;
    int result=0;
    TreeNode* ptr=root;
    int currentDepth=0;
    while(ptr!=NULL)
    {
        currentDepth++;
        if(currentDepth>result)
            result=currentDepth;
        if(ptr->left!=NULL)
        {
            sTreeNode.push(ptr->left);
            sDepth.push(currentDepth);
        }
        if(ptr->right!=NULL)
        {
            sTreeNode.push(ptr->right);
            sDepth.push(currentDepth);
        }
        if(!sTreeNode.empty())
        {
            ptr=sTreeNode.top();
            currentDepth=sDepth.top();
            sTreeNode.pop();
            sDepth.pop();
        } else
        {
            ptr=NULL;
        }
    }
    return result;

}
int main() {
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<maxDepth(root)<<endl;
    return 0;
}
