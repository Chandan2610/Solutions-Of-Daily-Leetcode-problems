#include<bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin>>x;
    if(x ==0 || x ==1){
        return x;
    }
    int start = 0;
    int end = x;
    int res =0;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid <= x/mid)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout<< res;
    }