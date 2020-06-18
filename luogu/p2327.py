n = int(input())
t = [0 for i in range(n+3)]
ss = input().split()
s = [0 for i in range(n+3)]
for i in range(n):
    s[i+1] = int(ss[i])
f = 1
ans = 0
if s[1] == 1 or s[1] == 0:
    t[1] = 0
    sum = 0
    for i in range(1, n):
        t[i+1] = s[i]-sum
        sum = sum-t[i-1]+t[i+1]
        if t[i+1] != 1 and t[i+1] != 0:
            f = 0
            break
    if t[n]+t[n-1] != s[n]:
        f = 0
    ans += f
f=1
if s[1] == 1 or s[1] == 2:
    t[1] = 1
    sum = 1
    for i in range(1, n):
        t[i+1] = s[i]-sum
        sum = sum-t[i-1]+t[i+1]
        if t[i+1] != 1 and t[i+1] != 0:
            f = 0
            break
    if t[n]+t[n-1] != s[n]:
        f = 0
    ans += f
print(ans)