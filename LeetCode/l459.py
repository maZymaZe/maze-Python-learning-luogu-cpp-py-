class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        l=len(s)
        if l<1:
            return False
        f=1
        for i in range(1,l):
            if s[0]==s[i] and l%i==0 :
                mh=s[0:i]
                g=1
                for j in range(l//i):
                    if s[j*i:j*i+i]!=mh:
                        g=0
                        break
                if g==1 :
                    return True
        return False

#人才做法：return s in (s+s)[1:-1]