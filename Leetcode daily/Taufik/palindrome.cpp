class Solution {
public:
    
    bool Check_Palindrome(int x, int left)
    {
        stringstream ss;
        ss<<x;
        string s;
        ss>>s;
		

        if(left > s.length()/2)
        {
            return true;
        }
        

        if(s[left] != s[s.length()-left-1])
        {
            return false;
        }
		
        return Check_Palindrome(x, left+1);
    }
    
    bool isPalindrome(int x)
    {
        int start = 0;
		
        if(!Check_Palindrome(x, start))
        {
            return false;
        }
        return true;      
    }
};