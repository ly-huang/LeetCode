//
//  main.cpp
//  leetcode133
//
//  Created by ly on 2020/8/12.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if(node==nullptr)
        return nullptr;
    Node* result=new Node(node->val);
    map<int,Node*> nodes;
    nodes[result->val]=result;
    queue<Node*> q;
    for(auto item:node->neighbors)
    {
        Node*temp=new Node(item->val);
        nodes[temp->val]=temp;
        result->neighbors.push_back(temp);
        q.push(item);
    }
    while(!q.empty())
    {
        Node *ptr=q.front();
        q.pop();
        for(auto item:ptr->neighbors)
        {
            if(nodes.find(item->val)==nodes.end())
            {
                Node*temp=new Node(item->val);
                nodes[temp->val]=temp;
                nodes[ptr->val]->neighbors.push_back(temp);
                q.push(item);
            }
            else
                nodes[ptr->val]->neighbors.push_back(nodes[item->val]);
        }
        
    }
    return result;
    
}

int main(int argc, const char * argv[]) {
    Node* node1=new Node(1);
    Node* node2=new Node(2);
    Node* node3=new Node(4);
    Node* node4=new Node(4);
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    auto result=cloneGraph(node1);
    return 0;
}
