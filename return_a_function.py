def lazy_sum(*args):
    def sum():
        ax=0
        for i in args :
            ax+=i
        return ax
    return sum
print(lazy_sum(*[1,2,3])())

def count():
    def  f(j):
        def g():
            return j*j
        return g
    fs=[]
    for k in range(1,4):
        fs.append(f(k))
    return fs
f1,f2,f3=count()
print(f1(),f2(),f3())     