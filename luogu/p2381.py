n = int(input())
tot = 0
t = []
for i in range(n):
    t.append(int(input()))
    tot += t[i]
ans = 0
fast = 0
slow = 0
nt = 0

while fast < n:
    while nt < tot/2:
        nt += t[fast]
        fast += 1
        if fast == n:
            break
    ans = max(min(nt, tot-nt), ans)
    ans = max(min(nt-t[fast-1], tot-(nt-t[fast-1])), ans)
    nt -= t[slow]
    slow += 1
print(ans)
