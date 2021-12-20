class Solution:
    def dayOfYear(self, date: str) -> int:
        t = date.split('-')
        s = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        y = int(t[0])
        if y % 400 == 0:
            s[2] += 1
        elif y % 100 == 0:
            pass
        elif y % 4 == 0:
            s[2] += 1
        base = 0
        for i in range(int(t[1])):
            base += s[i]
        return base+int(t[2])
