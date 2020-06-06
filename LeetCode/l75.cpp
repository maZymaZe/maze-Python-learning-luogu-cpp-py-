class Solution {
public:
    void sortColors(vector<int>& nums) {
       int p=0,q=nums.size()-1;
       for(int i=0;i<=q;i++){
           if(nums[i]==0)swap(nums[i],nums[p]),p++;
           else if(nums[i]==2)swap(nums[i],nums[q]),q--,i--;
           
       } 
    }
};