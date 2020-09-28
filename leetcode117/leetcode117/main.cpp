//
//  main.cpp
//  leetcode117
//
//  Created by ly on 2020/9/28.
//

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//层次遍历
//Node* connect(Node* root) {
//    if(root==nullptr)
//        return root;
//    queue<Node*> q;
//    q.emplace(root);
//    Node * node=nullptr;
//    int n=0;
//    while(!q.empty())
//    {
//        n=int(q.size());
//        for(int i=0;i<n;i++)
//        {
//            node=q.front();
//            q.pop();
//            if(i!=n-1)
//            {
//                node->next=q.front();
//            }
//            if(node->left!=nullptr)
//                q.emplace(node->left);
//            if(node->right!=nullptr)
//                q.emplace(node->right);
//        }
//    }
//    return root;
//}


//利用next的指针，使空间复杂度为常数级
Node* connect(Node* root) {
    if(root==nullptr)
        return nullptr;
    Node *node=root;
    Node *next=nullptr;
    Node *last=nullptr;
    while(node!=nullptr)
    {
        if(node->left!=nullptr)
        {
            if(next==nullptr)
                next=node->left;
            if(last!=nullptr)
                last->next=node->left;
            last=node->left;
        }
        if(node->right!=nullptr)
        {
            if(next==nullptr)
                next=node->right;
            if(last!=nullptr)
                last->next=node->right;
            last=node->right;
        }
        if(node->next!=nullptr)
            node=node->next;
        else
        {
            node=next;
            next=nullptr;
            last=nullptr;
        }
    }
    return root;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
