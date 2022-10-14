class Solution {
public:
    int check(int i,string s,int n){
        if(i+1 == n){
            return false;
        }
        if((s[i] <= '1' and s[i+1] <= '9') || (s[i] <= '2' and s[i+1] <= '6')){
            return true;
        }
        return false;
    }
    int solve(int i,string s,int n){
        if(i == n){
            return 0;
        }
        if(s[i] == '0'){
            return solve(i+1,s,n);
        }
        int ans1 = 0, ans2 = 0;
        if(check(i,s,n)){
            ans1 = 1 + solve(i+2,s,n);
        }
        ans2 = 1 + solve(i+1,s,n);
        return ans1 + ans2;
    }
    int numDecodings(string s) {
        int n = s.size();
        return solve(0,s,n);
    }
};
