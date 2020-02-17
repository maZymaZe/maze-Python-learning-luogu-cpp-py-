from math import ceil
pb = int(input())
cp, cs = map(int, input().split())
p = []
s = []
p.append(cp)
s.append(cs)
t1, t2 = map(int, input().split())
while t1 != -1 and t2 != -1:
    p.append(t1)
    s.append(t2)
    t1, t2 = map(int, input().split())
rd = int(input())
p.sort()
s.sort(reverse=True)


def fs(pr):
    global p, s, rd
    for i in range(len(p)):
        if p[i] == pr:
            return s[i]
        if i > 0 and p[i-1] < pr and p[i] > pr:
            return int((s[i]-s[i-1]/(p[i]-p[i-1])*(pr-p[i-1])+s[i-1]))
    if pr > p[len(p)-1]:
        return s[len(s)-1]-(pr-p[len(p)-1])*rd


sb = fs(pb)
sa = fs(pb-1)
sd = fs(pb+1)

lt = sa/(sa-sb)
rt = sd/(sb-sd)
if lt > rt:
    w = lt
    lt = rt
    rt = w
c = -1
la=ceil(lt)+cp-pb
ra=int(rt)+cp-pb
c=ceil(lt)
if c <= 0:
    print("NO SOLUTION")
else:
    if la<=0 and ra>=0:
        print(0)
    elif ra<0:
        print(ra)
    elif la>0:
        print(la)
