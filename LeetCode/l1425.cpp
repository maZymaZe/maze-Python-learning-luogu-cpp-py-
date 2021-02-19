class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int l=nums.size(),ans=-0x3f3f3f3f;
        deque<int> pos, val;
        for(int i=0; i<l; i++) {
            if(!pos.empty()&&pos.front()+k<i){
                pos.pop_front();
                val.pop_front();
            }
            int nv=nums[i];
            if(!val.empty())nv=max(nv,nv+val.front());
            while(!val.empty()&&nv>=val.back()){
                val.pop_back();
                pos.pop_back();
            }
            ans=max(ans,nv);
            val.push_back(nv);
            pos.push_back(i);
        }
        return ans;
    }
};