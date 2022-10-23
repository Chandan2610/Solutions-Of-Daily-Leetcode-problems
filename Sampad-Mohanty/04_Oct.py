# Given the root of a binary tree and an integer targetSum,
# return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
# A leaf is a node with no children.


class Solution:
    """
    Time:   O(n)
    Memory: O(n)
    """

    def hasPathSum(self, root: Optional[TreeNode], target: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None:
            return target == root.val
        return self.hasPathSum( root.left, target - root.val) or \
               self.hasPathSum(root.right, target - root.val)



