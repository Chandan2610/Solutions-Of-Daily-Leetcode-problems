class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size()-1;
        int i=0,j=n;
        if(n<2) return false;
        long long int one=2147483648,two=2147483648,three=2147483648;
        for(;i<=n;++i){
            // cout<<one<<" "<<two<<" "<<three;
            if(nums[i]>two){
                three=nums[i];
            }
            else if(nums[i]>one){
                if(nums[i]<two) two=nums[i]; 
            }
            else{
                if(nums[i]<one) one=nums[i]; 
            }
            if(three!=2147483648){
                
                cout<<one<<" "<<two<<three;
                return true;
            }
        }
        
        return false;
    }
};
