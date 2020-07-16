#include <iostream>
#include <vector>
 using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void insert(vector<int>& nums,int i,int j,TreeNode* &node)
{
    if(i>j)
        return;
    int index=(i+j)/2;
    node=new TreeNode(nums[index]);
    insert(nums,i,index-1,node->left);
    insert(nums,index+1,j,node->right);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* result=NULL;
    insert(nums,0,nums.size()-1,result);
    return result;
}

void printTree(TreeNode* note)
{
    if(note!=NULL)
        cout<<note->val<<" ";
    if(note->left!=NULL)
        printTree(note->left);
    if(note->right!=NULL)
        printTree(note->right);
}

int main() {
    vector<int> nums={-10,-3,0,5,9};
    TreeNode *result=sortedArrayToBST(nums);
    printTree(result);
    return 0;
}
