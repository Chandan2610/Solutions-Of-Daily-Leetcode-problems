// Que. Check if the Sentence Is Pangram
// A pangram is a sentence where every letter of the English alphabet appears at least once.
// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool flag[26]={false};
        for(char c:sentence)
            flag[c-'a']=true;
        for(int i=0;i<26;i++)
            if(!flag[i]) return false;
        return true;
    }
};