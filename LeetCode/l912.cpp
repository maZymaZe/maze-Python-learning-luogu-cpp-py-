class Solution {
public:
    void quicksort(vector<int>& nums,int l,int r){
        int mid=nums[(l+r)/2],i=l,j=r;
        while(i<=j){
            while(nums[i]<mid)i++;
            while(nums[j]>mid)j--;
            if(i<=j)swap(nums[i],nums[j]),i++,j--;
        }
        if(i<r)quicksort(nums,i,r);
        if(j>l)quicksort(nums,l,j);
    }
    vector<int> sortArray(vector<int>& nums) {
        int len=nums.size();
        quicksort(nums,0,len-1);
        return nums;
    }
};