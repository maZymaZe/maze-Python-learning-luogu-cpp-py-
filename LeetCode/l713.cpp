class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       if(k<2)return 0;
       int l=0,ans=0,tot=1,s=nums.size();
       for(int r=0;r<s;r++)
       {
           tot*=nums[r];
           while(tot>=k){
               tot/=nums[l];
               l++;
           }
           ans+=r-l+1;
       }
       return ans;
    }
};