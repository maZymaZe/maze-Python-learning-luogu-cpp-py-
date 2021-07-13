class Solution:
    def printBin(self, num: float) -> str:
        b=num*(1<<32)
        if abs(b-int(b))>0.0001:
            return "ERROR"
        c=int(b)
        t=[]
        for i in range(32):
            t.append(c%2)
            c//=2
        p=0
        while p<32 and t[p]==0:
            p+=1
        if p==32:
            return "0"
        ret="0."
        j=31
        while j>=p:
            ret+=str(t[j])
            j-=1
        return ret

    
