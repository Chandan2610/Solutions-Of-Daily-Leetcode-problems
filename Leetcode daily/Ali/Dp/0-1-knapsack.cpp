int knap(vector<int> &values, vector<int> &weights, int ind,int n, int w,vector<vector<int>> &dp){
    
    if(ind == n){
        return dp[ind][w] = 0;
    }
    
    if(dp[ind][w] != -1)
        return dp[ind][w];
    
    int x = 0, y = 0;
    
    if(w - weights[ind] >= 0){
         y = values[ind] + knap(values,weights,ind+1,n,w-weights[ind],dp);   
    }
    
    x = knap(values,weights,ind+1,n,w,dp);
    
    return dp[ind][w] = max(x,y);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    
    int ans;
    ans = knap(values,weights,0,n,w,dp);
    
    return ans;
}
