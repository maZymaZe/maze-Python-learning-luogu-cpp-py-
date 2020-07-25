bool ok(vector<int>& nums, int m,int mid){
    int l=nums.size(),cnt=1,tot=0;
    for(int i=0;i<l;i++){
        if(nums[i]>mid)return false;
        if(tot+nums[i]<=mid)tot+=nums[i];
        else{tot=nums[i],cnt++;}
        if(cnt>m)return false;
    }
    return cnt<=m;
}
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left=0,right=2147483647,mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(ok(nums,m,mid))right=mid;
            else left=mid+1;
        }
        return left;
    }
};