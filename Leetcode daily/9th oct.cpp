class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans;
        int min=INT_MAX;
        for(int i=0;i<n-2;i++){
               int l=i+1, r= n-1;
               while(l<r){
                   int sum =nums[i]+nums[l]+nums[r];
                   if(abs(sum-target)<min){  // updating the sum if sum  so far. is closest to target
                      min=abs(sum-target);
                      ans=sum;
                   }
                   if(sum<target) l++;        //
                   else if(sum>target)r--;
                   else {
                       ans=sum;  // we have sum equal to target which is closest so no need to check further 
                       i=n-2;  // for breaking the outer for loop
                       break;  // for breaking current while loop
                   }
               }
        }
        return ans;
    }
};
