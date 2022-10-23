'''Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].
If no such indices exists, return false.'''

class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        
        first, second = inf, inf
        
        for third in nums:
            
            if second < third: return True
            if third <= first: first= third    
            else:  second = third 
                
        return  False
