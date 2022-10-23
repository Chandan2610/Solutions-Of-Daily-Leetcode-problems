# You have n dice, and each die has k faces numbered from 1 to k.
# Given three integers n, k, and target, return the number of possible ways
# (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.

class Solution:
    @lru_cache(maxsize=None)
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:

        if target <= 0 or n*k < target :
            return 0

        if n==1:
            return int(target <= k)

        for i in range(1, k+1):
            ans = sum(self.numRollsToTarget(n-1,k,target-i)
                     for i in range(1, k+1))
        
        return ans % (10**9+7)
