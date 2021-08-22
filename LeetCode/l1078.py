class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        ret = []
        wl = text.split()
        l = len(wl)
        for i in range(2, l):
            if wl[i-2] == first and wl[i-1] == second:
                ret.append(wl[i])
        return ret
