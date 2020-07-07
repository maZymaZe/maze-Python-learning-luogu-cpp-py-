class Solution:
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k==0:
            return []
        if longer==shorter:
            return [shorter*k,]
        else :
            return [shorter*k+i*(longer-shorter) for i in range(k+1)]