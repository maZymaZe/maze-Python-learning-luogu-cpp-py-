class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        mx=1
        for i in range(1,int(area**0.5)+1):
            if area%i==0 :
                mx=i
        t=[]
        t.append(area//mx)
        t.append(mx)
        return t