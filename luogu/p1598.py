c=[]
rt=[]
for i in range(26):
    c.append(0)
for i in range(4):
    s=input()
    for j in s:
        if ord(j)<=ord('Z') and ord(j)>=ord('A'):
            c[ord(j)-ord('A')]+=1
h=0
for i in range(26):
    if c[i]>=h:
        h=c[i]
for i in range(h):
    ls=0
    for j in range(26):
        if c[j]>= (h-i):
            ls=j
    rt.append(ls)

for i in range(h):
    for j in range(rt[i]+1):
        if c[j]>=h-i:
            print('* ',end='')
        else :
            print('  ',end='')
    print('')
for i in range(ord('A'),ord('Z')+1):
    print(chr(i),end=' ')

