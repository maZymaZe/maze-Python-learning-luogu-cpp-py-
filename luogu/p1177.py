n=int(input())
t=input().split()
s=[]
for i in t:
    s.append(int(i))
s.sort()
for i in s:
    print(i,end=' ')