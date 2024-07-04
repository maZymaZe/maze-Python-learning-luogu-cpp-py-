class Solution {
   public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int l = nums.size(), cnt1 = 0;
        long long ans = (long long)l * k;
        vector<int> v;
        for (int i = 0; i < l; i++) {
            cnt1 += nums[i];
            if (nums[i])
                v.push_back(i);
        }
        if (cnt1 == 0)
            return k * 2;
        int winsz = max(1, k - maxChanges), cgs, vsz = v.size();
        cgs = k - winsz;
        for (int i = 0; i < 3; i++) {
            if (winsz > vsz || cgs < 0)
                continue;
            int midpos = (winsz) / 2;
            int llen = midpos;
            long long tot = 0, tmpmx;
            for (int j = 0; j < winsz; j++) {
                tot += abs(v[j] - v[midpos]);
            }
            tmpmx = tot;
            for (int j = winsz; j < vsz; j++) {
                tot += v[j - winsz];
                tot -= v[midpos + 1];
                tot -= v[midpos];
                tot += v[j];
                // 12 3 45  23 4 56
                // 12 3 456  23 4 567
                if (winsz % 2 == 0) {
                    tot -= v[midpos];
                    tot += v[midpos + 1];
                }
                midpos++;
                tmpmx = min(tmpmx, tot);
            }
            ans = min(ans, tmpmx + 2 * cgs);
            winsz++;
            cgs--;
        }
        return ans;
    }
};