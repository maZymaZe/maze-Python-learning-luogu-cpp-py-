print(sorted([36,5,-12,9,-21]))
print(sorted([36,5,-12,9,-21],key=abs))
def ma(n):
    return -1*n
print(sorted([36,5,-12,9,-21],key=ma)) 