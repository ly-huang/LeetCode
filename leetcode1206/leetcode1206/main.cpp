//
//  main.cpp
//  leetcode1206
//
//  Created by ly on 2020/9/23.
//

#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

class Skiplist {
public:
    Skiplist()
    {
        levels_=1;
        max_level_=12;
        head_=new SkiplistNode(INT_MIN,nullptr);
    }
    ~Skiplist()
    {
        SkiplistNode *ptr=head_;
        SkiplistNode *temp=nullptr;
        while(ptr!=nullptr)
        {
            temp=ptr;
            ptr=ptr->next[0];
            delete temp;
        }
    }
    bool search(int target)
    {
        int l=levels_-1;
        SkiplistNode *ptr=head_;
        while(true)
        {
            if(ptr->next[l]!=nullptr&&ptr->next[l]->key<target)
                ptr=ptr->next[l];
            else if(ptr->next[l]!=nullptr&&ptr->next[l]->key==target)
                return true;
            else
            {
                if(l==0)
                    return false;
                else
                    --l;
            }
        }
    }
    
    void add(int num)
    {
        int random_level=randomLevel();
        SkiplistNode *newNode=nullptr;
        add_(num,levels_-1,head_,random_level,newNode);
        while(random_level>levels_)
        {
            newNode->next.emplace_back(nullptr);
            head_->next.emplace_back(newNode);
            levels_++;
        }
    }
    
    bool erase(int num)
    {
        int l=levels_-1;
        SkiplistNode *ptr=head_;
        while(true)
        {
            if(ptr->next[l]!=nullptr&&ptr->next[l]->key<num)
                ptr=ptr->next[l];
            else if(ptr->next[l]!=nullptr&&ptr->next[l]->key==num)
            {
                SkiplistNode *temp=ptr->next[l];
                while (l>=0)
                {
                    while(ptr->next[l]!=temp)
                        ptr=ptr->next[l];
                    ptr->next[l]=temp->next[l];
                    --l;
                }
                while(head_->next.back()==nullptr)
                {
                    head_->next.pop_back();
                    levels_--;
                }
                delete temp;
                return true;
            }
            else
            {
                if(l==0)
                    return false;
                else
                    --l;
            }
        }

        
    }
    void print()
    {
        SkiplistNode *ptr;
        for(int i=levels_-1;i>=0;i--)
        {
            ptr=head_->next[i];
            while(ptr!=nullptr)
            {
                cout<<ptr->key<<"->";
                ptr=ptr->next[i];
            }
            cout<<endl;
        }
        cout<<endl<<endl<<endl;
    }
private:
    struct SkiplistNode
    {
        int key;
        vector<SkiplistNode*> next;
        SkiplistNode(int k,SkiplistNode* node):key(k){next.emplace_back(node);}
    };
    void add_(int num,int level,SkiplistNode *ptr,const int &random_level,SkiplistNode *&newNode)
    {
        while(ptr->next[level]!=nullptr&&ptr->next[level]->key<num)
            ptr=ptr->next[level];
        if(level==0)
        {
            newNode=new SkiplistNode(num,ptr->next[level]);
            ptr->next[level]=newNode;
            return;
        }
        else
        {
            add_(num, level-1, ptr, random_level, newNode);
        }
        if(random_level>level)
        {
            newNode->next.emplace_back(ptr->next[level]);
            ptr->next[level]=newNode;
        }
    }
    int randomLevel()
    {
        int random_level = 1;
        int seed = time(0);
        static default_random_engine e(seed);
        static uniform_int_distribution<int> u(0, 1);

        while (u(e) && random_level < max_level_)
        {
            random_level++;
        }
        return random_level;
    }
    int levels_;
    int max_level_;
    SkiplistNode *head_;
};

int main(int argc, const char * argv[]) {
    Skiplist sl;
    vector<string>fun={"add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","search","add","erase","search","erase","search","erase","erase","erase","add","erase","add","search","erase","search","add","erase","erase","erase","add","erase","erase","add","erase","add","erase","search","erase","search","search","erase","search","search","add","erase","search","search","erase","search","add","add","search","erase","search","search","search","add","search","add","add","add","add","search","erase","add","search","add","search","erase","add","add","add","erase","search","search","search","add","add","erase","add","erase","add","search","add","search","search","search","search","erase","add","erase","search","search","search","search","erase","search","erase","add","add","add","search","erase","search","search","add","add","erase","add","erase","search","erase","search","erase","add","search","search","search","search","search","search","search","search","search","search","search","search","search","search","search"};
    vector<int>data={22,25,0,11,8,1,22,3,26,15,14,3,28,17,26,21,20,11,2,17,14,9,24,13,10,29,4,25,28,7,8,29,2,9,0,23,2,3,6,9,26,1,18,13,0,15,18,7,2,9,22,1,12,13,12,15,4,19,14,21,6,3,8,1,24,1,26,27,0,21,16,27,22,23,28,5,2,9,16,1,16,23,8,5,6,19,6,27,0,21,26,5,14,25,24,21,4,21,28,25,28,23,8,27,24,1,8,17,4,21,4,19,8,23,4,11,22,25,6,9,28,11,8,25,6,5,18,29,20,15,2,3,26,15,6};
    vector<bool> result={true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,false,true,true,false,true,true,false,false,false,true,false,true,true,true,false,true,false,false,false,true,false,false,true,false,true,true,true,false,false,true,true,false,false,true,true,true,true,false,false,true,true,true,false,true,false,false,true,true,true,true,true,true,false,true,true,false,true,true,false,true,true,true,false,false,true,false,true,true,true,true,false,true,true,true,true,true,false,true,true,true,true,true,false,true,false,true,true,true,true,true,true,true,false,true,false,true,true,true,true,true,false,true,false,true,true,false,false,true,false,true,false,false,false,true,true,true,true,true,true,true};
    int n=int(fun.size());
    for(int i=0;i<n;i++)
    {
        if(fun[i]=="add")
        {
            cout<<"add: "<<data[i]<<endl;
            sl.add(data[i]);
            sl.print();
        }
        else if(fun[i]=="erase")
        {
            bool temp=sl.erase(data[i]);
            cout<<"erase: "<<data[i]<<": "<<temp<<endl;
            sl.print();
            if(temp!=result[i])
            {
                cout<<"error"<<endl;
                return 0;
            }
        }
        else if(fun[i]== "search")
        {
            bool temp=sl.search(data[i]);
            cout<<"search: "<<data[i]<<": "<<temp<<endl;
            sl.print();
            if(temp!=result[i])
            {
                cout<<"error"<<endl;
                return 0;
            }
        }
    }
    return 0;
}
