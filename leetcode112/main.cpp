#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)
        return false;
    int currentSum=0;
    stack<TreeNode*> node;
    stack<int> getSum;
    TreeNode*ptr=root;
    do{

        currentSum+=ptr->val;
        if(ptr->left==NULL&&ptr->right==NULL)
        {
            if(currentSum==sum)
                return true;
        }

        if(ptr->right!=NULL)
        {
            node.push(ptr->right);
            getSum.push(currentSum);
        }
        if(ptr->left!=NULL)
        {
            node.push(ptr->left);
            getSum.push(currentSum);
        }
        if(!node.empty())
        {
            ptr=node.top();
            node.pop();
            currentSum=getSum.top();
            getSum.pop();
        } else
            break;
    }while(true);
    return false;
}
int main() {
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->right=new TreeNode(1);
    cout<<hasPathSum(root,22)<<endl;
    return 0;
}
