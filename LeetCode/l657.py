class Solution:
    def judgeCircle(self, moves: str) -> bool:
        rl=0
        ud=0
        for i in moves:
            if i=='R':
                rl+=1
            elif i=='L':
                rl-=1
            elif i=='U':
                ud+=1
            else:
                ud-=1
        return ud==0 and rl==0
        
