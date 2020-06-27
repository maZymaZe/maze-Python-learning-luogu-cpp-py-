class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l=len(nums)
        flag=False
        begin=0
        end=0
        tot=0
        ans=0
        while begin < l:
            while end < l and tot < s:
                tot += nums[end]
                end += 1
            if tot>=s:
                if flag == False:
                    ans = end-begin
                    flag = True
                else:
                    ans = min(ans, end-begin)
            tot -= nums[begin]
            begin += 1
        return ans
