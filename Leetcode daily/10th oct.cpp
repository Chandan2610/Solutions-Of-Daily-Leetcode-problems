class Solution {
public:
    string breakPalindrome(string S) {
        int n=S.length();
        if(n==1) return "";
        // int j=0;
        // int n = S.size();
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return n < 2 ? "" : S;
        
    }
};
