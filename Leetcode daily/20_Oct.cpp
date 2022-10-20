class Solution {
public:
    string intToRoman(int n) {
        vector <string> rom ={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector <int> num ={1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
        string ans="";
         for(int i=0;i<num.size();i++){
            while(n>=num[i]){
                 ans += rom[i];
                 n -=num[i];
             }
         }
        return ans;
    }
};