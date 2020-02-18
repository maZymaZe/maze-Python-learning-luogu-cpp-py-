n=input()
t=input().split()
s=set()
for i in t:
    s.add(int(i))
print(len(s))
r=[]
for i in s:
    r.append(i)
r.sort()
for i in r:
    print(i,end=' ')