print(int('12',16))
print(int('12',base=8))

def int2(x,base=2):
    return int(x,base=2)

print(int2('1000'))

import functools
int3=functools.partial(int,base=3)
print(int3('121'))