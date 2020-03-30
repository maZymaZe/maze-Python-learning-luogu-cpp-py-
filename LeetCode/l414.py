class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        m1=-99999999999999
        for i in nums:
            if i>m1 :
                m1=i
        m2=-99999999999999999
        for i in nums:
            if i>m2 and i!=m1: 
                m2=i
        m3=-99999999999999999
        for i in nums:
            if i>m3 and i!=m1 and i!=m2: 
                m3=i
        if m3==-99999999999999999:
            return m1
        else :
            return m3