f=[]
for i in range(1024):
    f.append(1)
j=int(input())
for i in range(2,j+1):
    for k in range(1,(i)//2+1):
        f[i]+=f[k]
print(f[j])
