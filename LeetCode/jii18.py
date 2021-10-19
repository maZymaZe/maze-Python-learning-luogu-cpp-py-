class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        t=[]
        for i in s:
            if (ord(i)>=ord("0") and ord(i)<=ord("9")) or (ord(i)>=ord("a") and ord(i)<=ord("z")):
                t.append(i)
        l=len(t)
        if l==0:
            return True
        for i in range(0,l//2):
            if t[i]!=t[l-1-i]:
                return False
        return True