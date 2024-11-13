class Solution {
   public:
    vector<long long> countKConstraintSubstrings(string s,
                                                 int k,
                                                 vector<vector<int>>& queries) {
        int n = s.size();
        int cnt[2] = {0};
        vector<int> right(n, n);
        vector<long long> pf(n + 1, 0);
        int i = 0;
        for (int j = 0; j < n; j++) {
            cnt[s[j] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[i] - '0']--;
                right[i] = j;
                i++;
            }
            pf[j + 1] = pf[j] + j - i + 1;
        }
        vector<long long> ans;
        for (auto& v : queries) {
            int l = v[0], r = v[1];
            int i = min(right[l], r + 1);
            long long part1 = 1ll * (i - l + 1) * (i - l) / 2;
            long long part2 = pf[r + 1] - pf[i];
            ans.push_back(part1 + part2);
        }
        return ans;
    }
};