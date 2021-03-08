class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l=nums.size();
        vector<int> v;
        for(int i=0;i<l;i++){
            if(v.empty())v.push_back(nums[i]);
            else if(nums[i]>v.back())v.push_back(nums[i]);
            else{
                int t=lower_bound(v.begin(), v.end(),nums[i])- v.begin();
                v[t]=nums[i];
            }
            if(v.size()==3)return true;
        }
        return false;
    }
};