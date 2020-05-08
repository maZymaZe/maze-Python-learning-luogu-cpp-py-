n = int(input())
a, b = map(int, input().split())
ma1 = a + b
mi1 = a + b
ma2 = a - b
mi2 = a - b
for i in range(1, n):
    a, b = map(int, input().split())
    ma1 = max(a + b,ma1)
    mi1 = min(mi1,a + b)
    ma2 = max(ma2,a - b)
    mi2 = min(mi2,a - b)
print(max(ma1-mi1,ma2-mi2))