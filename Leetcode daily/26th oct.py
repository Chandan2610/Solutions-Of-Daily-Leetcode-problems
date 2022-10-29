class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        lookup = {0:-1}
        curr_sum = 0
        
        for i, n in enumerate(nums):
            if k != 0:
                curr_sum = (curr_sum + n) % k
            else:
                curr_sum += n
            if curr_sum not in lookup:
                lookup[curr_sum] = i
            else:
                if i - lookup[curr_sum] >= 2:
                    return True
        return False
