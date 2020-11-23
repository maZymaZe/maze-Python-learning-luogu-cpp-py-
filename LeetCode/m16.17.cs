public class Solution {
    public int MaxSubArray(int[] nums) {
        int l=nums.Length,ans=int.MinValue,sum=0;
        for(int i=0;i<l;i++){
            sum=Math.Max(sum+nums[i],nums[i]);
            ans=Math.Max(ans,sum);
        }
        return ans;
    }
}