n=int(input())
s=[1,1]
if n>1:
    for i in range(2,n+1):
        s.append(s[i-1]+s[i-2])
s[0]=0
print(s[n])