class Solution:
    def freqAlphabets(self, s: str) -> str:
        res=''
        l=len(s)
        i=0
        while i<l:
            if i+2<l and s[i+2]=='#':
                res+=(chr(ord('j')+int(s[i:i+2])-10))
                i+=3
            else:
                res+=chr(ord('a')+int(s[i])-1)
                i+=1
        return res