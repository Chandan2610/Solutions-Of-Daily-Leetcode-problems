// QUESTION
// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// SOLUTION
#include<bits/stdc++.h>
using namespace std;

// 1st solution 
class Solution {
public:
    
    // custom sort 
    static bool cmp(pair<int,string>&a, pair<int,string>&b){
        // put that pair first whose first value greater than the first value of other pair 
        // if pairs contain same first value put that pair first whose second value is lexicographically smaller 
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // store the final answer 
        vector<string>ans;
        
        // store the count of string and string as a pair where pair having greater count of string comes first and if pairs having same count then the pair contain lexicographically smaller string comes first 
        vector<pair<int,string>>v;
        
        // as we have to count the value of same string and store it thats why using map 
        map<string,int>m;
        
        int len=words.size();
        
        for(int i=0;i<len;i++){
            m[words[i]]++;
        }
        
        for(auto&it:m){
            v.push_back({it.second,it.first});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        
        for(auto&it:v){
            if(k){
                ans.push_back(it.second);
                k--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
// Time Complexity O(NlogN)
// Space Complexity O(N)
// N=size of vector words



// 2nd solution 
class Solution {
public:
    
    // custom sort 
    class cmp {
        public:
        bool operator() (const pair<int,string>&a, const pair<int,string>&b){
            // put that pair at top whose first value smaller than the first value of other pair 
            // if pairs contain same first value put that pair at top whose second value is lexicographically larger 
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        // store the final answer 
        vector<string>ans;
        
        // store the count of string and string as a pair where pair having smaller count of string comes at top and if pairs having same count then the pair contain lexicographically larger string comes at top  
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;  //min heap 
        // as we have to take k values having high count value that's why take min heap so that we can remove the (n-k) top values contain smaller value of count 
        
        // as we have to count the value of same string and store it thats why using map 
        unordered_map<string,int>m;
        
        int len=words.size();
        
        for(int i=0;i<len;i++){
            m[words[i]]++;
        }
        
        // now we iterate for lets say n values and at a time we have maximum of k values in priority queue thats why nlogk
        for(auto&it:m){
            // pq.push({it.second,it.first});
            pq.push(make_pair(it.second,it.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
// Time Complexity O(NlogK)
// Space Complexity O(N)
// N=size of vector words