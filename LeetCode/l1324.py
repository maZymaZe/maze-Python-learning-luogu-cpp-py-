class Solution:
    def printVertically(self, s: str) -> List[str]:
        t=s.split()
        ma=0
        ans=[]
        for i in t:
            ma=max(ma,len(i))
        for i in range(0,ma):
            ts=""
            r=0
            for j in range(len(t)):
                if len(t[len(t)-j-1])>=i+1:
                    r=len(t)-j-1
                    break
            for j in range(r+1):
                if len(t[j])<i+1:
                    ts=ts+' '
                else :
                    ts=ts+t[j][i]
            ans.append(ts)
        return ans

