def f(x):
    return x*x
'''
l=list(range(1,11))
m=map(f,l)
print(l)
print(list(l))
print(list(m))
'''

def st(str):
    if(ord(str[0])>=ord('a')):
        str=chr(ord(str[0])+ord('A')-ord('a'))+str[1:]
    for i in range(1,len(str)-1):
        if(ord(str[i])<ord('a')):
            str=str[:(i)]+chr(ord(str[i])-ord('A')+ord('a'))+str[(i+1):]
    if(ord(str[len(str)-1])<=ord('Z')):
        str=str[:len(str)-1]+chr(ord(str[len(str)-1])-ord('A')+ord('a'))    
    return str
l=['adam', 'LISA', 'barT']
print(list(map(st,l)))
