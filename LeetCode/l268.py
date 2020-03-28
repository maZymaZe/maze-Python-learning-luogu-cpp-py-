class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l=len(nums)
        l=(l+1)*l//2
        for i in nums:
            l-=i
        return l