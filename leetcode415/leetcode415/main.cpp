//
//  main.cpp
//  leetcode415
//
//  Created by ly on 2020/8/3.
//  Copyright © 2020 ly. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    string result="";
    int index1=num1.length()-1;
    int index2=num2.length()-1;
    int add=0;
    for(;index1>=0&&index2>=0;index1--,index2--)
    {
        int sum=num1[index1]-'0'+num2[index2]-'0'+add;
        result+=((sum%10)+'0');
        add=sum/10;
    }
    for(;index1>=0;index1--)
    {
        int sum=num1[index1]-'0'+add;
        result+=((sum%10)+'0');
        add=sum/10;
    }
    for(;index2>=0;index2--)
    {
        int sum=num2[index2]-'0'+add;
        result+=((sum%10)+'0');
        add=sum/10;
    }
    if(add!=0)
    {
        result+=(add+'0');
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    cout<<addStrings("987", "555")<<endl;
    return 0;
}
