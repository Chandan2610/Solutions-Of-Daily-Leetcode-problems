// QUESTION 
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

// A substring is a contiguous sequence of characters within the string.

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

// ANSWER 
// FOOD FOR THOUGHTS
// 1 Use two pointers to create a window of letters in s, which would have all the characters from t.
// 2 Expand the right pointer until all the characters of t are covered.
// 3 Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.
// 4 Continue expanding the right and left pointers until you reach the end of s.

# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int lens=s.size(),lent=t.size();
        
        unordered_map<char,int>m,check;
        for(int i=0;i<lent;i++){
            check[t[i]]++;
            m[t[i]]=0;
        }
        
        // minlen to store the minimum length substring which contains all the characters of string t along with duplicates
        // leftind to store the starting index of substring of minlen which which contain all the characters of string t
        // count to check whether we cover all the characters of string t or not 
        int minlen=INT_MAX,leftind=-1,count=0;
        
        int left=0,right=-1;
        while(left<lens and right<lens){
            if(count!=lent){
                
                // advance left until we didn't found character which is present in string t and left<right 
                while(left<right and m.find(s[left])==m.end()){
                    left++;
                }
                
                right++;
                if(m.find(s[right])!=m.end()){
                    
                    // advance count only when count of character present in m point by right is less than check
                    if(m[s[right]]<check[s[right]]){
                        count++;
                    }
                    
                    m[s[right]]++;
                }
            }
            if(count==lent){
                // found  string of length less than minlen and count value is equal to lent that ensure we found all the characters of string t than update minlen & leftind
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    leftind=left;
                }
                
                // before forwarding left pointer we check if character point by left index is in map m or not if it is then we have to update values 
                if(m.find(s[left])!=m.end()){
                    m[s[left]]--;
                    
                    // count of character point Y left present in string t R stored in check & if that count is greater than the actual count present in m than count--
                    if(m[s[left]]<check[s[left]]){
                        count--;
                    } 
                }
                
                left++;
            }
        }
        
        // INT_MAX ensure that we didn't found t in s 
        if(minlen==INT_MAX){
            return "";
        }
        else{
            return s.substr(leftind,minlen);
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        Solution sol;
        cout<<sol.minWindow(s,t)<<endl;
    }
}
