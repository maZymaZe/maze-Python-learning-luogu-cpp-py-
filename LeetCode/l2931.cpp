class Solution {
   public:
    long long maxSpending(vector<vector<int>>& values) {
        vector<int> v;
        for (const auto& i : values) {
            for (int j : i)
                v.push_back(j);
        }
        sort(v.begin(), v.end());
        int l = v.size();
        long long ans = 0;
        for (int i = 0; i < l; i++) {
            ans += (long long)(i + 1) * v[i];
        }
        return ans;
    }
};