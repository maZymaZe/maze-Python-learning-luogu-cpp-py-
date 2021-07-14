class Solution {
   public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long MOD = 1e9 + 7, tot = 0;
        int l = nums1.size();
        for (int i = 0; i < l; i++) {
            (tot += abs(nums1[i] - nums2[i])) %= MOD;
        }
        long long effect = 0;
        auto s1 = nums1;
        sort(s1.begin(), s1.end());
        for (int i = 0; i < l; i++) {
            auto it = lower_bound(s1.begin(), s1.end(), nums2[i]);
            if (it != s1.end())
                effect =
                    max(effect,(long long) abs(nums2[i] - nums1[i]) - abs(*it - nums2[i]));
            if (it != s1.begin())
                effect = max(
                    effect, (long long)abs(nums2[i] - nums1[i]) - abs(*(--it) - nums2[i]));
        }
        tot=(tot-effect+MOD)% MOD;
        return tot;
    }
};