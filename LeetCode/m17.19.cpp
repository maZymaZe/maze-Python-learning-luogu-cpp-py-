class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int l=nums.size();
        l+=2;
        int sum=(1+l)*l/2;
        for(int i:nums){
            sum-=i;
        }
        int half=sum/2;
        int sum1=(half+1)*half/2;
        for(auto i:nums){
            if(i<=half)sum1-=i;
        }
        return {sum1,sum-sum1};     
    }
};