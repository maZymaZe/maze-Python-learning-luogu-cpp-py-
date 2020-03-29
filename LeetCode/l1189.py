class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cb=0
        ca=0
        cl=0
        co=0
        cn=0
        for i in text:
            if i=='b':
                cb+=1
            if i=='a':
                ca+=1
            if i=='l':
                cl+=1
            if i=='o':
                co+=1
            if i=='n':
                cn+=1
        mx=9999
        mx=min(mx,cb)
        mx=min(mx,ca)
        mx=min(mx,cl//2)
        mx=min(mx,co//2)
        mx=min(mx,cn)
        return mx
            