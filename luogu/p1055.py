s=input()
d=int(s[0])+2*int(s[2])+3*int(s[3])+4*int(s[4])+5*int(s[6])+6*int(s[7])+7*int(s[8])+8*int(s[9])+9*int(s[10])
r=d%11
if r!=10:
    if str(r)==s[12]:
        print('Right')
    else :
        print(s[:12],end='')
        print(r)
else:
    if 'X'==s[12]:
        print('Right')
    else :
        print(s[:12],end='')
        print('X')
