class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n=len(img1)
        a1=[(i,j) for i in range(n) for j in range(n) if img1[i][j]]
        b1=[(i,j) for i in range(n) for j in range(n) if img2[i][j]]
        cnt=Counter((xa-xb,ya-yb) for xa,ya in a1 for xb,yb in b1)
        return max(cnt.values() or [0])
