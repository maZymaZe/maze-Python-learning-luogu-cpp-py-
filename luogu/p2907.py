n, k = map(int, input().split())
t = []
t.append(n)
h = 0
tail = 1
ans = 1
f = k % 2
ff = k//2
while h < tail:
    if t[h] % 2 == f and t[h]//2 > ff:
        t.append(t[h]//2-ff)
        t.append(t[h]-(t[h]//2-ff))
        tail += 2
        ans += 1
    h += 1
print(ans)
