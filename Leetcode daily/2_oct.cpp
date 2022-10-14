class Solution {
public:
    int mod = 1e9+7;
    int solve(int n,int k,int sum,vector<vector<int>> &dp){        
        if(n == 0){
            if(sum == 0){
                return 1;
            }
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int ans = 0;
        for(int val = 1; val <= k; val++){
            if(sum - val >= 0){
                ans = ((ans%mod) + solve(n-1,k,sum-val,dp)%mod)%mod;
            }else{
                break;
            }
        }
        return dp[n][sum] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};