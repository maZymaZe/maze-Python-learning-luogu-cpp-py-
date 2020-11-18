public class Solution {
    public int PeakIndexInMountainArray(int[] arr) {
        int l=arr.Length;
        for(int i=1;i<l-1;i++){
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])return i;
        }
        return 0;
    }
}