n = int(input())
n %= 26
s = input()
t = []
for i in range(len(s)):
    t.append(0)
for i in range(len(s)):
    t[i] = ord(s[i])+n
for i in range(len(s)):
    if t[i] > ord('z'):
        t[i] -=26
for i in range(len(s)):
    print(chr(t[i]), end='')
