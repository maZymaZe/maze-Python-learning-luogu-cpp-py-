import copy
l1=[1]
l1.append(l1)
print(l1)

l1=[1,[2,3],4]
l2=l1
#l3=l1[:]
l3=copy.deepcopy(l1)
l1[0]=10
l3[2]=[40]
l2[1][1]=30
print(l1)
print(l2)
print(l3)