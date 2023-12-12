struct PR {
    int a, b;
    bool operator<(const PR& other) {
        if (a == other.a)
            return b > other.b;
        return a < other.a;
    }
};
class Solution {
   public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<PR> v;
        int l = nums.size();
        for (int i = 0; i < l; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        map<int, int> mp;
        vector<int> ans(l);
        for (int i = l - 1; i >= 0; i--) {
            auto it = mp.lower_bound(v[i].b);
            if (it == mp.end()) {
                ans[v[i].b] = -1;
                mp[v[i].b] = v[i].a;
                continue;
            }
            ++it;
            if (it == mp.end()) {
                ans[v[i].b] = -1;
                mp[v[i].b] = v[i].a;
                continue;
            }
            ans[v[i].b] = it->second;
            mp[v[i].b] = v[i].a;
        }
        return ans;
    }
};