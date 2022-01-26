class Solution:
    def countValidWords(self, sentence: str) -> int:
        t = sentence.split(' ')
        ans = 0
        for i in t:
            l = len(i)
            if l == 0:
                continue
            suc = 1
            ul = 0
            for j in range(l):
                if i[j] == '-':
                    if ul:
                        suc = 0
                        break
                    ul = 1
                    if not (j > 0 and j < l-1 and ord(i[j+1]) >= ord('a') and ord(i[j+1]) <= ord('z') and ord(i[j-1]) >= ord('a') and ord(i[j-1]) <= ord('z')):
                        suc = 0
                        break
                elif not(ord(i[j]) >= ord('a') and ord(i[j]) <= ord('z')):
                    if ord(i[j]) >= ord('0') and ord(i[j]) <= ord('9'):
                        suc = 0
                        break
                    elif j != l-1:
                        suc = 0
                        break
            ans += suc
        return ans


Solution().countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.")
