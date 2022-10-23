'''Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.'''

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        lo = 0
        hi = len(nums)-1
        while lo <= hi:
            if (lo+hi)%2 == 0: mid = (lo+hi)/2
            else: mid = (lo+hi-1)/2

            if nums[mid] == target: return mid
            elif nums[mid] < target:
                if lo == hi: return mid+1
                lo = mid+1
            else:
                if lo == hi: return mid
                hi = mid
