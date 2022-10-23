// QUESTION
// You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
// You are given an integer array nums representing the data status of this set after the error.
// Find the number that occurs twice and the number that is missing and return them in the form of an array.

// Example 1:
// Input: nums = [1,2,2,4]
// Output: [2,3]

// ANSWER
#include<bits/stdc++.h>
using namespace std;

// 1st solution 
// store the numbers in hash and their frequency and check for the number whose frequency is zero and the number whose frequency is 2 and store them in a answer 
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
        int len=nums.size();
        vector<int>hash(len,0);
        for(int i=0;i<len;i++){
            hash[nums[i]-1]++;
        }
        for(int i=0;i<len;i++){
            if(hash[i]==0){
                ans[1]=i+1;
            }
            if(hash[i]==2){
                ans[0]=i+1;
            }
        }
        return ans;
    }
};
// TIME COMPLEXITY O(N);
// SPACE COMPLEXITY O(N);

// 2nd solution 
// two numbers two equation basic math
// missing number - repeating number = x
// square(missing number) - square(repeating number) = y  <===> (missing number - repeating number)*(missing number + repeating number) = y
// missing number + repeating number = y/x = z
// missing number = (x+z)/2
// repeating number = z-missing number

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans(2);
        long long len=nums.size();
        long long actual_sum=len*(len+1)/2;
        long long given_sum=accumulate(nums.begin(),nums.end(),0);
        long long square_actual_sum=len*(len+1)*(2*len+1)/6;
        long long square_given_sum=0;
        for(int i=0;i<len;i++)
            square_given_sum+=(nums[i]*nums[i]);
        long long mis_minus_rep=actual_sum-given_sum;
        long long mis_minus_rep_square=square_actual_sum-square_given_sum;
        long long mis_plus_rep=mis_minus_rep_square/mis_minus_rep;
        int mis=(mis_minus_rep+mis_plus_rep)/2;
        int rep=mis_plus_rep-mis;
        ans[0]=rep;ans[1]=mis;
        return ans;
    }
};
// TIME COMPLEXITY O(N);
// SPACE COMPLEXITY O(1);

// 3rd solution 
// Example 
// [1,2,2,4] given list
// [1,2,3,4] original list
// xor of num^num = 0 and num^0 = num
// xor= 1^1^2^2^2^3^4^4 = 2^3= 1(001)
// rightmost_set_bit=(001) & (111) = 001(1)
// as xor of 1 = 001, 2 = 010, 3 = 011, 4 = 100
// onenumber^= 1^1^3=3
// anothernumber^= 2^2^2^4^4=2
// return {anothernumber,onenumber}

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len=nums.size(),xorr=0;
        
        // we take xor of all the numbers in nums array and xor of number from 1 to n
        // as num^num==0 all the numbers got cancel except the one missing number which appear 1 time odd and the repeating number which appear 3 time odd 
        // xor contain xor or missing number and repeating number 
        for(int i=0;i<len;i++){
            xorr^=nums[i];
            xorr^=i+1;
        }
        
        // 2's complement it is used to find rightmost set bit in xor and and make all others bit unset
        // now we make number having only rightmost bit set and all other bits are unset
        // now the number contain set bit which is obtain by xor that means either missing or repeating number contain 1(one number contain one and another one zero)
        // so we divide the numbers in the two buckets on the basis of containing rightmost set bit and rightmost unset bit
        int rightmost_set_bit=xorr & ~(xorr-1);
        
        int onenumber=0,anothernumber=0;
        for(int i=0;i<len;i++){
            if(rightmost_set_bit & (i+1)){
                onenumber^=(i+1);
            }
            else{
                anothernumber^=(i+1);
            }
            if(rightmost_set_bit & nums[i]){
                onenumber^=nums[i];
            }
            else{
                anothernumber^=nums[i];
            }
        }
        for(int i=0;i<len;i++){
            if(onenumber==nums[i]){
                return {onenumber,anothernumber};
            }
        }
        return {anothernumber,onenumber};
    }
};
// TIME COMPLEXITY O(N);
// SPACE COMPLEXITY O(1);