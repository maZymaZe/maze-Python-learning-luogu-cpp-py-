class mmm(object):
    def __init__(self,lh,rh):
        self.lh=lh
        self.rh=rh
    def gk(self):
        return self.rh*self.lh
n=int(input())
l,r=map(int,input().split())
st=[]
for i in range(n):
    a,b=map(int,input().split())
    tt=mmm(a,b)
    st.append(tt) 
st=sorted(st,key=mmm.gk)
mx=1
d=l
for i in range(n):
    t=d//(st[i]).rh
    if t>mx:
        mx=t
    d*=(st[i]).lh
print(mx)
