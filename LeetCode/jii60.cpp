struct pr {
    int u, v;
    bool operator<(const pr& x) { return (v > x.v) || (v == x.v && u < x.u); }
};
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            if (mp.count(nums[i]))
                mp[nums[i]]++;
            else
                mp.insert({nums[i], 1});
        }
        int l2 = mp.size(), p = 0;
        vector<pr> v(l2);
        for (auto i = mp.begin(); i != mp.end(); ++i, ++p) {
            v[p] = {i->first, i->second};
        }
        sort(v.begin(), v.end());
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
            ans[i] = (v[i].u);
        return ans;
    }
};