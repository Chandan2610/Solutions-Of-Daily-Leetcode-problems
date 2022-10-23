# Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths.
# If it is impossible to form any triangle of a non-zero area, return 0.

class Solution(object):
    def largestPerimeter(self, A):
        A.sort()
        for i in range(len(A) - 3, -1, -1):
            if A[i] + A[i+1] > A[i+2]:
                return A[i] + A[i+1] + A[i+2]
        return 0
