# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(preorder)==0:
            return None
        x=inorder.index(preorder[0])
        t=TreeNode(preorder[0])
        t.left =self.buildTree(preorder[1:(x+1)],inorder[0:x])
        t.right =self.buildTree(preorder[(x+1):len(preorder)],inorder[(x+1):len(inorder)])
        return t