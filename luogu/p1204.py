class ppr(object) :
    def __init__(self, b, g):
        self.b = b
        self.g = g
    def getb(self):
        return self.b
    def getg(self):
        return self.g

n = int(input())
t = []
for i in range(n):
    l, r = map(int, input().split())
    tmp=ppr(l, r)
    t.append(tmp)
t.sort(key=ppr.getb)
bb = t[0].getb()
gg = t[0].getg()
m1 = bb-gg
m2 = 0
for i in range(1, n):
    if t[i].getb() > gg:
        m2 = max(m2, t[i].getb()-gg)
        bb = t[i].getb()
        gg = t[i].getg()
    else:
        gg = max(gg, t[i].g)
        m1 = max(m1, gg-bb)
m1 = max(m1, gg-bb)
print("%d %d" % (m1, m2))
