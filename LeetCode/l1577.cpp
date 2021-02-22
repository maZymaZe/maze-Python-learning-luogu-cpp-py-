class Solution {
   public:
    unordered_map<long long, int> mp;
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size(), ans = 0;
        for (int i = 0; i < l1; i++) {
            long long t = nums1[i];
            t *= t;
            if (mp.count(t))
                mp[t]++;
            else
                mp[t] = 1;
        }
        for (int i = 0; i < l2; i++) {
            for (int j = i + 1; j < l2; j++) {
                long long s = (long long)nums2[i] * nums2[j];
                if (mp.count(s))
                    ans += mp[s];
            }
        }
        mp.clear();
        for (int i = 0; i < l2; i++) {
            long long t = nums2[i];
            t *= t;
            if (mp.count(t))
                mp[t]++;
            else
                mp[t] = 1;
        }
        for (int i = 0; i < l1; i++) {
            for (int j = i + 1; j < l1; j++) {
                long long s = (long long)nums1[i] * nums1[j];
                if (mp.count(s))
                    ans += mp[s];
            }
        }
        return ans;
    }
};