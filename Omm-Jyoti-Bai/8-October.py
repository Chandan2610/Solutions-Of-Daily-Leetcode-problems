# Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
# Return the sum of the three integers.

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        return self.kSumClosest(nums, 3, target)
    def kSumClosest(self, nums, k, target):
        N = len(nums)
        if N == k:
            return sum(nums[:k])
        if sum(nums[:k]) >= target:
            return sum(nums[:k])
        if sum(nums[-k:]) <= target:
            return sum(nums[-k:])
        if k == 1:
            deltas = [(x, abs(target-x)) for x in nums]
            return min(deltas, key = lambda x: x[1])
        closest = sum(nums[:k])
        for i,x in enumerate(nums):
            # small optimization to handle duplicate x values
            if i>0 and nums[i-1] == x:
                continue        
            bestMatch = self.kSumClosest(nums[i+1:], k-1, target-x)
            current = x + bestMatch
            if abs(target-current) < abs(target-closest):
                if target == current:
                    return current
                else:
                    closest = current 
        return closest
