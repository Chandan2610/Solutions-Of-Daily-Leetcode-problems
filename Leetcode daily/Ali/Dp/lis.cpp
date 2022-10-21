class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
        }
        
        int maxi = 0;
        for(auto it : lis)
            maxi = max(maxi,it);
        
        return maxi;
    }
};
