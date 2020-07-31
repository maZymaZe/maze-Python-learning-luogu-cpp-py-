class Solution:
    def smallestSubsequence(self, text: str) -> str:
        st=[]
        seen=set()
        last={c:i for i,c in enumerate(text)}
        for i,c in enumerate(text):
            if c not in seen:
                while st and c<st[-1] and i<last[st[-1]]:
                    seen.discard(st.pop())
                seen.add(c)
                st.append(c)
        return ''.join(st)