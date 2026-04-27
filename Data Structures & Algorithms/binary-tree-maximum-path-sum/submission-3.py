# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_split = float("-inf")

        def dfs(root):
            if not root:
                return 0
            
            left = max(dfs(root.left), 0)
            right = max(dfs(root.right), 0)

            self.max_split = max(self.max_split, left + root.val + right)

            return max(root.val, root.val + left, root.val + right)
        dfs(root)
        return self.max_split