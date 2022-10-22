// QUESTION
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

// Example 1:
// Input: num = 3
// Output: "III"
// Explanation: 3 is represented as 3 ones.

// ANSWER 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string find(int&forward,vector<pair<int,string>>&v,int&num,int&digits){
        int len=v.size();
        int start=0,end=len-1;
        
        // store the corresponding string of forward
        string ans;
        
        // store the corresponding number of forward as there may be case when forward is not present in a vector in that case we take lower bound of forward
        int temp;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(v[mid].first<=forward){
                ans=v[mid].second;
                temp=v[mid].first;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(temp==forward){
            // if forward is present then the remaining number is num%digits like for 589 we search for 500 and remaining number is 89
            num=num%digits;
        }
        else{
            // if forward is not present then the remaining number is num-temp like for 789 we search for 700 but found 500 so remaining number is 289
            num=num-temp;
        }
        return ans;
    }
    
    string intToRoman(int num) {
        // ans to store the final roman string 
        string ans=""; 
        
        // store all the value and their symbol as a pair which we had given in a question 
        vector<pair<int,string>>v{{1,"I"},{4,"IV"},{5,"V"},{9,"IX"},{10,"X"},{40,"XL"},{50,"L"},{90,"XC"},{100,"C"},{400,"CD"},{500,"D"},{900,"CM"},{1000,"M"}};
        
        while(num){
            // extract the digit from left to right and multiply with 10 to the power number of digit -1 
            // like if number is 789 we extract 7 and multiply with 100 to make 700 
            int number_of_digits=log10(num)+1;
            int powof10=pow(10,number_of_digits-1);
            int forward=num-(num%powof10);
            
            // search for a string corresponding to given number forward like for 700 it's 'D' and concatenate in answer 
            ans+=find(forward,v,num,powof10);
            cout<<num<<" ";
        }
        return ans;
    }
};