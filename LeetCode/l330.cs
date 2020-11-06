public class Solution
{
    public int MinPatches(int[] nums, int n)
    {
        int patches = 0, i = 0;
        long miss = 1;
        while (miss <= n)
        {
            if (i < nums.Length && nums[i] <= miss)
            {
                miss += nums[i++];
            }
            else
            {
                miss += miss;
                patches++;
            }
        }
        return patches;
    }
}