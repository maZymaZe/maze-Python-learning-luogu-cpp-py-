class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l=nums.size();
        auto q=nums.end();q--;
        auto p=q;
        while(p!=nums.begin()){
            q--;
            if((*q)<(*p)){
                reverse(p,nums.end());
                auto t=upper_bound(p,nums.end(),*q);
                swap(*q,*t);
                return;
            }
            p--;
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};