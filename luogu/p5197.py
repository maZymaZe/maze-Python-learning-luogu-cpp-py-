n=int(input())
t=[1 for i in range(n+1)]
for i in range(n-1):
    a,b=map(int,input().split())
    t[a]+=1
    t[b]+=1
print(max(t))