class Solution {
   public:
    int len;
    vector<int> N;
    long long ck(int x) {
        if (!x)
            return 0;
        unordered_map<int, int> mp;
        long long tot = 0;
        int tp = 0, e = 0;
        for (int i = 0; i < len; i++) {
            mp[N[i]]++;
            if (mp[N[i]] == 1)
                tp++;
            while (tp > x) {
                mp[N[e]]--;
                if (mp[N[e]] == 0)
                    tp--;
                e++;
            }
            tot += i - e + 1;
        }
        return tot;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        N = nums;
        len = nums.size();
        long long lim = ((long long)len * (len + 1) / 2 + 1) / 2;
        int l = 0, r = len, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            long long tot = ck(mid);
            if (tot == lim)
                return mid;
            else if (tot < lim)
                l = mid;
            else
                r = mid - 1;
        }
        return l + 1;
    }
};