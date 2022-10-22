// QUESTION
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true

// ANSWER

#include<bits/stdc++.h>
using namespace std;

// 1st solution 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // size of nums vector
        int len=nums.size();
        
        // hashmap to store the number and their indices as a key value pair 
        unordered_map<int,int>m;
        
        // check whether current number is already present or not if if is present check for absolute difference of their indices if it's less than equal to k return true
        // if number not present make pair in hash map && if present then update index as we have to move rightward we have to take rightmost index for making absolute difference minimum
        for(int i=0;i<len;i++){
            if(m.find(nums[i])!=m.end() and abs(m[nums[i]]-i)<=k){
                return true;
            }
            m[nums[i]]=i;
        }
        
        return false;
    }
};
// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(N)

// 2nd solution 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // size of nums vector
        int len=nums.size();
        
        // vector to store number and their indices as a pair in a non-decreasing order
        vector<pair<int,int>>v;
        
        // make pair 
        for(int i=0;i<len;i++){
            v.push_back({nums[i],i});
        }
        
        // sort the vector of pair in a non-decreasing order 
        sort(v.begin(),v.end());
        
        // check whether is there any consecutive pair having same values and absolute difference of indices less than equal to k 
        for(int i=1;i<len;i++){
            if(v[i].first==v[i-1].first and abs(v[i].second-v[i-1].second)<=k){
                return true;
            }
        }
        
        return false;
    }
};
// TIME COMPLEXITY O(NlogN)
// SPACE COMPLEXITY O(N)