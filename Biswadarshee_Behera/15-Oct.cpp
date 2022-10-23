// Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

// Notice that in this problem, we are not adding '1' after single characters.

// Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

// Find the minimum length of the run-length encoded version of s after deleting at most k characters.

// int cache[101][27][101][101];


class Solution {
public:
  int getLengthOfOptimalCompression(string s, int k) {    
    memset(cache, -1, sizeof(cache));
    // Min length of compressioned string of s[i:]    
    // 1. last char is |last|
    // 2. current run-length is len
    // 3. we can delete k chars.
    function<int(int, int, int, int)> dp = 
      [&](int i, int last, int len, int k) {
      if (k < 0) return INT_MAX / 2;
      if (i >= s.length()) return 0;      
      int& ans = cache[i][last][len][k];
      if (ans != -1) return ans;
      if (s[i] - 'a' == last) { 
        // same as the previous char, no need to delete.
        int carry = (len == 1 || len == 9 || len == 99);
        ans = carry + dp(i + 1, last, len + 1, k);
      } else {
        ans = min(1 + dp(i + 1, s[i] - 'a', 1, k),  // keep s[i]
                      dp(i + 1, last, len, k - 1)); // delete s[i]
      }
      return ans;
    };
    return dp(0, 26, 0, k);
  }
};
