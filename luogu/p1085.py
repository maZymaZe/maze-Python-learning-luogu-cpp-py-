s=[]
for i in range(0, 7):
    a,b=map(int,input().split())
    s.append(a+b)
mt = 8
d = 0
for i in range(0, 7):
    if s[i] > mt:
        mt = s[i]
        d = i+1
print(d)
