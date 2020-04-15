m, n = map(int, input().split())
w = n-m
t = [1, 1]
for i in range(2, w+1):
    t.append(t[i-1]+t[i-2])
print(t[w])
