#include <iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
    int i=n-1,j=0;
    int num=0;
    while(i>=0&&j<n)
    {
        while(i>=0&&matrix[i][j]>mid)
            i--;
        if(i>=0)
        {
            num+=i+1;
            j++;
        }
    }
    return num>=k;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    while(left<right)
    {
        int mid = (left + right) / 2;
        if(check(matrix,mid,k,n))
            right=mid;
        else
            left=mid+1;
    }
    return left;
}

int main() {
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    cout<<kthSmallest(matrix,k)<<endl;
    return 0;
}