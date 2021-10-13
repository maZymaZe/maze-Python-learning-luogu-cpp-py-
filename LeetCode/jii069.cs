public class Solution {
    public int PeakIndexInMountainArray(int[] arr) {
         int l=arr.Length,ll=1,rr=l-2;
        int mid=(ll+rr)/2;
        while(ll<=rr){
            mid=(ll+rr)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])return mid;
            else if(arr[mid]<arr[mid-1])rr=mid-1;
            else ll=mid+1;
        }
        return rr;
    }
}