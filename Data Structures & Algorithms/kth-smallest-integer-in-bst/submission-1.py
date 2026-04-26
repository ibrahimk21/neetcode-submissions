# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.k = k
        self.res = None
        def inorder(root):
            if not root or self.res:
                return
            inorder(root.left)

            self.k -= 1
            if self.k == 0:
                self.res = root.val
                return
            
            inorder(root.right)
        inorder(root)
        return self.res