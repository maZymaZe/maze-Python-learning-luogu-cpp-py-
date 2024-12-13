struct PR {
    int v, pos;
    bool operator<(const PR& x) const {
        if (v == x.v)
            return pos < x.pos;
        return v < x.v;
    }
};
class Solution {
   public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int l = nums.size();
        set<PR> s;
        for (int i = 0; i < l; i++) {
            s.insert({nums[i], i});
        }
        for (int i = 0; i < k; i++) {
            PR x = *s.begin();
            x.v *= multiplier;
            s.erase(s.begin());
            s.insert(x);
        }
        vector<int> ans(l);
        for (PR x : s) {
            ans[x.pos] = x.v;
        }
        return ans;
    }
};