class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mi=0x3f3f3f3f,tot=0,l=nums.size();
        for(int i=0;i<l;i++){
            tot+=nums[i];
            mi=min(mi,tot);
        }
        return max(1-mi,1);

    }
};