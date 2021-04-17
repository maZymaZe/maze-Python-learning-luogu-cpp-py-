class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> ms;
        int l=nums.size();
        for(int i=0;i<k;i++){
            if(i<l){
                ms.insert(nums[i]);
            }else break;
        }
        for(int i=0;i<l;i++){
            if(i+k<l)ms.insert(nums[i+k]);
            if(i-k>0)ms.erase(ms.find(nums[i-k-1]));
            ms.erase(ms.find(nums[i]));
            auto tt=ms.lower_bound(nums[i]);
            if(tt!=ms.end()){
                if(abs(*tt-nums[i])<=t)return true;
            }
            if(tt!=ms.end()&&tt!=ms.begin()){
                --tt;
                if(abs(*tt-nums[i])<=t)return true;
            }
            ms.insert(nums[i]);
        }
        return false;
    }
};