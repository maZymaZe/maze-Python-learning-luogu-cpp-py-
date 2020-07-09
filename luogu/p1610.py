n, d = map(int, input().split())
ttt = input().split()
t = [int(i) for i in ttt]
t.sort()
ans = 0
b = t[0]
bt = 0
for i in range(1, n):
    if t[i] > b+d:
        if i-bt > 2:
            ans += i-bt-2
        '''
        while  t[i]>b+d:
            bt+=1
            b = t[bt]
        '''
        bt=i-1
        b=t[bt]            
if n-1-bt>1:
    ans+=n-1-bt-1
print(ans)
