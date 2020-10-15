//
//  main.cpp
//  leetcode116
//
//  Created by ly on 2020/10/15.
//

#include <iostream>
using namespace std;


struct Node {
    int val;
    Node *left=nullptr;
    Node *right=nullptr;
    Node *next=nullptr;
    Node(int v):val(v){}
};

Node* connect(Node* root) {
    if(root==nullptr)
        return nullptr;
    Node *ptr=root;
    Node *next=root->left;
    while(ptr->left!=nullptr)
    {
        while(ptr!=nullptr)
        {
            ptr->left->next=ptr->right;
            if(ptr->next!=nullptr)
            {
                ptr->right->next=ptr->next->left;
                ptr=ptr->next;
            }
            else
                break;
        }
        ptr=next;
        next=ptr->left;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    connect(root);
    return 0;
}
