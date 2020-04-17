# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
   
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(n1,n2):
            if n1==None and n2==None:
                return True
            elif not n1 or not n2:
                return False
            if n1.val!=n2.val:
                return False
            return check(n1.left,n2.right) and check(n1.right,n2.left)
        return check(root,root)
            

        