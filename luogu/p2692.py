n=[0,0]
m=[0,0]
n[0],n[1],m[0],m[1]=map(int,input().split())
cnt=[0,0]
for i in range(2):
    cf=[0 for _ in range(n[i]+3)]
    for j in range(m[i]):
        l, r =map(int, input().split())
        cf[l]+=1
        cf[r+1]-=1
    tot=0
    for j in cf:
        tot+=j
        cnt[i]+=(tot>0)
ans=cnt[0]*n[1]+cnt[1]*n[0]-cnt[0]*cnt[1]
print(ans)