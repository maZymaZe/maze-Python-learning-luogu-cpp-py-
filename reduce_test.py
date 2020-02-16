from functools import reduce


def mp(a, b):
    return a*b


l = list(range(1, 11))

print(reduce(mp, l))
