class Solution {
   public:
    vector<int> ta;
    int N;
    void add1(int x) {
        while (x <= N) {
            ta[x]++;
            x += x & -x;
        }
    }
    int query(int x) {
        int ans = 0;
        while (x > 0) {
            ans += ta[x];
            x -= x & -x;
        }
        return ans;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[nums1[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            nums2[i] = pos[nums2[i]];
        }
        long long ans = 0;
        N = n;
        ta.resize(n + 1);
        fill(ta.begin(), ta.end(), 0);
        vector<int> dp1(n), dp2(n);
        for (int i = 0; i < n; i++) {
            dp1[i] = query(nums2[i] + 1);
            add1(nums2[i] + 1);
        }
        fill(ta.begin(), ta.end(), 0);
        for (int i = n - 1, j = 0; i >= 0; j++, i--) {
            dp2[i] = j - query(nums2[i] + 1);
            add1(nums2[i] + 1);
        }
        for (int i = 1; i < n - 1; i++) {
            ans += (long long)dp1[i] * dp2[i];
        }
        return ans;
    }
};