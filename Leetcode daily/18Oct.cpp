

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s1="1";
        while(--n){
            string s2="";
            int m=s1.length();
            for(int i=0;i<m;i++){
                int count=1;
                while(i+1<m && s1[i]==s1[i+1])
                    count++,i++;
                s2+=to_string(count);
                s2+=s1[i];
            }
            s1=s2;
        }
        return s1;
    }
};