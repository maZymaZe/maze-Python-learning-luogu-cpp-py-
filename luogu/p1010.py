n = int(input())
t = []
t1 = 1
for i in range(16):
    t.append(t1)
    t1 *= 2


def dv(s):
    if s == 1:
        print("2(0)", end='')
    if s == 2:
        print("2", end='')
    elif s > 1:
        f = 1
        for i in range(16):
            if s >= t[15-i]:
                s -= t[15-i]
                if f == 1: 
                    f = 0
                    if 15-i == 1:
                        print("2", end='')
                    elif 15-i == 0:
                        print("2(0)", end='')
                    else:
                       
                        print("2(", end='')
                        dv(15-i)
                        print(")", end='')

                else:
                    if 15-i == 1:
                        print("+2", end='')
                    elif 15-i == 0:
                        print("+2(0)", end='')
                    else:
                        print("+2(", end='')
                        dv(15-i)
                        print(")", end='')


dv(n)
