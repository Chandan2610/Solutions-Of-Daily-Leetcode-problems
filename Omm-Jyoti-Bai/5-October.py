# Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.
# Note that the root node is at depth 1.
class Solution:
    def addOneRow(self, root, val, depth, isLeft = True):

        if depth != 1:
            if not root: return
            root.left = self.addOneRow(root.left, val,depth-1, True)
            root.right = self.addOneRow(root.right, val,depth-1, False)
            return root 
        
        return TreeNode(val,root) if isLeft else TreeNode(val,None, root)
