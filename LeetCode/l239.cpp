class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = nums.size();
        deque<int> pos, val;
        for (int i = 0; i < k; i++) {
            while (!val.empty() && nums[i] > val.back()) {
                val.pop_back();
                pos.pop_back();
            }
            val.push_back(nums[i]);
            pos.push_back(i);
        }
        int anssz=l-k+1,p=k;
        vector<int> ans(anssz);
        ans[0]=val.front();
        for(int i =1;i<anssz;i++){
            if(pos.front()<i){
                pos.pop_front();
                val.pop_front();
            }
            while (!val.empty() && nums[p] > val.back()) {
                val.pop_back();
                pos.pop_back();
            }
            val.push_back(nums[p]);
            pos.push_back(p);
            p++;
            ans[i]=val.front();
        }
        return ans;
    }
};