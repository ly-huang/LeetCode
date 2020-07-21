#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
void print(TreeNode *node){
    if(node== nullptr)
        return;
    queue<TreeNode *> q;
    TreeNode *ptr=node;
    q.push(ptr);
    while(!q.empty())
    {
        ptr=q.front();
        q.pop();
        if(ptr!= nullptr)
        {
            cout<<ptr->val<<" ";
            q.push(ptr->left);
            q.push(ptr->right);
        } else{
            cout<<"null ";
        }
    }
    cout<<endl;
}
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> result;
    if(n<=0)
        return result;
    result.push_back(new TreeNode(1));
    for(int i=2;i<=n;i++)
    {
        vector<TreeNode*> temp; //复制当前的树
        for(auto node:result)
        {
            TreeNode* ptr1=node;
            TreeNode* ptr2=new TreeNode(ptr1->val);
            temp.push_back(ptr2);
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            q1.push(ptr1);
            q2.push(ptr2);
            while(!q1.empty())
            {
                ptr1=q1.front();
                ptr2=q2.front();
                q1.pop();
                q2.pop();
                if(ptr1->left!= nullptr)
                {
                    ptr2->left=new TreeNode(ptr1->left->val);
                    q1.push(ptr1->left);
                    q2.push(ptr2->left);
                }
                if(ptr1->right!= nullptr)
                {
                    ptr2->right=new TreeNode(ptr1->right->val);
                    q1.push(ptr1->right);
                    q2.push(ptr2->right);
                }
            }
        }
        int n=result.size();
        for(int j=0;j<n;j++)
        {
            TreeNode*ptr=result[j];
            while(ptr->right!= nullptr)
            {
                TreeNode* ptr1=result[j]; //复制当前的树
                TreeNode* ptr2=new TreeNode(ptr1->val);
                TreeNode* index;
                result.push_back(ptr2);
                queue<TreeNode*> q1;
                queue<TreeNode*> q2;
                q1.push(ptr1);
                q2.push(ptr2);
                while(!q1.empty())
                {
                    ptr1=q1.front();
                    ptr2=q2.front();
                    q1.pop();
                    q2.pop();
                    if(ptr1==ptr)
                    {
                        index=ptr2;

                    }
                    if(ptr1->left!= nullptr)
                    {
                        ptr2->left=new TreeNode(ptr1->left->val);
                        q1.push(ptr1->left);
                        q2.push(ptr2->left);
                    }
                    if(ptr1->right!= nullptr)
                    {
                        ptr2->right=new TreeNode(ptr1->right->val);
                        q1.push(ptr1->right);
                        q2.push(ptr2->right);
                    }
                }
                index->right=new TreeNode(i,index->right, nullptr);
                ptr=ptr->right;
            }
            ptr->right=new TreeNode(i);
        }
        for(auto node:temp)
        {
            TreeNode *ptr=new TreeNode(i,node, nullptr);
            result.push_back(ptr);
        }
    }
    return result;
}
int main() {
    auto result=generateTrees(3);
    for (auto ptr:result)
        print(ptr);
    return 0;
}
