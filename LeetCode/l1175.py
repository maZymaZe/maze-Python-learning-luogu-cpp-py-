class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        a,b=0,0
        for i in range(1,n+1):
            if i==1:
                a+=1
            else:
                c=2
                f=0
                while c*c<=i:
                    if i%c==0:
                        f=1
                        break
                    c+=1
                if f==0:
                    b+=1
                else:
                    a+=1
        ans=1
        while a>1:
            ans*=a
            a-=1
            ans%=1000000007
        while b>1:
            ans*=b
            b-=1
            ans%=1000000007
        return ans