class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int lcs[text1.size() + 1][text2.size() + 1];
        
        for(int i = text1.size() ; i >= 0; i--){
            for(int j = text2.size(); j >= 0; j--){
                if(i == text1.size() || j == text2.size())
                    lcs[i][j] = 0;
                else if(text1[i] == text2[j])
                    lcs[i][j] = 1 + lcs[i+1][j+1];
                
                else 
                    lcs[i][j] = max(lcs[i+1][j],lcs[i][j+1]);
            }
        }
        
        return lcs[0][0];
    }
};
