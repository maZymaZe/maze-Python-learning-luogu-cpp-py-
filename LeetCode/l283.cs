public class Solution {
    public void swap(ref int a,ref int b){
        int t=a;
        a=b;
        b=t;
    }
    public void MoveZeroes(int[] nums) {
        int l=nums.Length,i=0,j=0;
        while(i<l&&j<l){
            while(i<l&&nums[i]!=0)i++;
            j=i+1;
            while(j<l&&nums[j]==0)j++;
            if(j>=l)break;
            nums[i]=nums[j];nums[j]=0;
            i++;
        }
    }
}