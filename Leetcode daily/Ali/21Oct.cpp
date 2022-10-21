class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto it : mp){
            vector<int> ind = it.second;
            for(int i=0;i<ind.size();i++){
                for(int j=i+1;j<ind.size();j++){
                    if(abs(ind[i] - ind[j]) <= k)
                        return true;
                }
            }
        }
        
        return false;
    }
};
