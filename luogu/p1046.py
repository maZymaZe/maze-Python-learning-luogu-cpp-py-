s=input().split()
h=int(input())+30
c=0
for i in range(10):
    if h>=int(s[i]):
        c+=1
print(c)