class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A)<3:
            return 0
        f=0
        for i in range(1,len(A)):
            if A[i]==A[i-1]:
                return 0
            if A[i]<A[i-1] and f==0 :
                f=1
            elif A[i]>A[i-1] and f==1:
                return 0
        if A[0]>=A[1]:
            return 0
        if f==1:
            return 1
        return 0
