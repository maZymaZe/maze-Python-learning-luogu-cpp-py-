# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def ck(self,mid:int,d:int,root:TreeNode)->bool:
        l,r=0,2**d - 1
        for i in range(d):
            t=l+(r-l)//2
            if mid<=t:
                root=root.left
                r=t
            else:
                root=root.right
                l=t+1
        return root is not None
    def countNodes(self, root: TreeNode) -> int:
        if root==None:
            return 0
        dep=0
        tmp=root
        while tmp.left!=None:
            dep+=1
            tmp=tmp.left
        l,r=1,2**dep - 1
        while l<=r:
            mid=l+(r-l)//2
            if(self.ck(mid,dep,root)):
                l=mid+1
            else:
                r=mid-1
        return (2**dep - 1) + l
        