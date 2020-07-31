class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        st=[]
        seen=set()
        last={c:i for i,c in enumerate(s)}
        for i,c in enumerate(s):
            if c not in seen:
                while st and c<st[-1] and i<last[st[-1]]:
                    seen.discard(st.pop())
                seen.add(c)
                st.append(c)
        return ''.join(st)