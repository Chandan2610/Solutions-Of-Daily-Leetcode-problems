// Que.
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e9;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            int tar=target-nums[i];
            while(j<k){
              int sum=nums[j]+nums[k];
              if(abs(sum-tar)<abs(ans-target))
                  ans=sum+nums[i];
              if(sum<tar)
                  j++;
              else
                  k--;
            }
        }
        return ans;
    }
};