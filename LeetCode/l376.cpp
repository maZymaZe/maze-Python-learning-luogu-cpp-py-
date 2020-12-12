class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int l=nums.size(),ans=1,pre,cnt=1;
        if(l<2)return l;
        pre=(nums[1]-nums[0]);
        ans=(pre)?2:1;
        for(int i=2;i<l;i++){
            int dif=nums[i]-nums[i-1];
            if((dif>0&&pre<=0||(dif<0&&pre>=0))){
                ans++;
                pre=dif;
            }
        }
        return ans;
    }
};