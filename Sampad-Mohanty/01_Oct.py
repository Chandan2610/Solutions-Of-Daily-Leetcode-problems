'''A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.'''


class Solution:
    # number of ways to do something -> think about dp
    def numDecodings(self, s):
        if s[0] == '0':
            return 0
        n = len(s)
        dp = [0 for _ in range(n + 1)]
        dp[0] = 1
        for i in range(1, n + 1):
            
            if s[i - 1] != '0':
                dp[i] = dp[i - 1]
        
            if i >= 2:
                
                x = int(s[i - 2: i])
                if 10 <= x <= 26:
                    dp[i] += dp[i - 2]
        return dp[n]
