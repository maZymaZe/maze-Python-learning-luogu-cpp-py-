def md():
    t=1
    x=input()
    for i in range(len(x)):
        t*=(ord(x[i])-ord('A')+1)
    return t%47
a=md()
b=md()
if a==b:
    print('GO')
else:
    print('STAY')

