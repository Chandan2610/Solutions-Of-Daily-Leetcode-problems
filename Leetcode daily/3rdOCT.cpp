class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        vector<int>v;
        v.push_back(neededTime[0]);
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                v.push_back(neededTime[i]);
            }
            else{
                if(v.size()<=1){
                    v.clear();
                    v.push_back(neededTime[i]);
                }
                else{
                    sort(v.begin(),v.end());
                    for(int i=0;i<v.size()-1;i++){
                        ans+=v[i];
                    }
                    v.clear();
                    v.push_back(neededTime[i]);
                }
            }
        }
        if(v.size()<=1){
                    v.clear();
                    // v.push_back(neededTime[i]);
                }
                else{
                    sort(v.begin(),v.end());
                    for(int i=0;i<v.size()-1;i++){
                        ans+=v[i];
                    }
                    v.clear();
                    // v.push_back(neededTime[i]);
                }
        return ans;
    }
};
