//
//  main.cpp
//  leetcode649
//
//  Created by ly on 2020/12/11.
//

#include <iostream>
#include <string>
using namespace std;

string predictPartyVictory(string senate) {
    int R=0;
    int D=0;
    int n=int(senate.length());
    int c_R=0;
    int c_D=0;
    for(const auto &i:senate)
    {
        if(i=='R')
            c_R++;
        else
            c_D++;
    }
    for(int i=0;c_R!=0&&c_D!=0;i=(i+1)%n)
    {
        if(senate[i]=='R')
        {
            if(D!=0)
            {
                senate[i]='O';
                D--;
                c_R--;
            }
            else
                R++;
        }
        else if(senate[i]=='D')
        {
            if(R!=0)
            {
                senate[i]='O';
                R--;
                c_D--;
            }
            else
                D++;
        }
    }
    if(c_R!=0)
        return "Radiant";
    return "Dire";
}


int main(int argc, const char * argv[]) {
    cout<<predictPartyVictory("RD")<<endl;
    return 0;
}
