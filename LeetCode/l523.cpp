class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int l=nums.size();
        long long ps=0,sm=nums[0]%k;
        for(int i=1;i<=nums.size();i++){
            if(s.count(sm))return true;
            s.insert(ps);
            ps=sm;
            if(i==nums.size())break;
            sm=(sm+nums[i])%k;
        }
        return false;
    }
};