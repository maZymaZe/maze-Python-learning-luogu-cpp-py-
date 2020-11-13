public class Solution {
    public int PivotIndex(int[] nums) {
        int tot=0,ltot=0;
        for(int i=0;i<nums.Length;i++){
            tot+=nums[i];
        }
        for(int i=0;i<nums.Length;i++){
            if(ltot*2==tot-nums[i])return i;
            ltot+=nums[i];
        }
        return -1;
    }
}