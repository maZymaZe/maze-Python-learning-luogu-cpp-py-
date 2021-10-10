class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        for i in paths:
            arr = i.split()
            for j in range(1, len(arr)):
                t = arr[j].split('(')
                d.setdefault(t[1], [])
                d[t[1]].append(arr[0]+'/'+t[0])
        return [i for i in d.values() if len(i) > 1]
