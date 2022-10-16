
// Que. Minimum Difficulty of a Job Schedule

// You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).
// You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.
// You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].
// Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int ind,vector<int>& jobs,int d,int prev,vector<vector<vector<int>>>& dp){
        if(ind==-1){
            if(d==0) return jobs[prev];
            else return 1e9;
        }
        if(dp[ind][d][prev]!=-1) return dp[ind][d][prev];
        int notselect=1e9;
        if(d>0)
            notselect=jobs[prev]+find(ind-1,jobs,d-1,ind,dp);
        int select=find(ind-1,jobs,d,jobs[prev]>jobs[ind]?prev:ind,dp);
        return dp[ind][d][prev]=min(select,notselect);
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        d--;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(d+1,vector<int>(n+1,-1)));
        int ans= find(n-2,jobDifficulty,d,n-1,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};