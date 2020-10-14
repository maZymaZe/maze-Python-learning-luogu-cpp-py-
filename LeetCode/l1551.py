class Solution:
    def minOperations(self, n: int) -> int:
        if n&1==0 :
            return n*n//4
        else:
            return (1+n)*(n//2)//2