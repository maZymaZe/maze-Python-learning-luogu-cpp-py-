class Solution {
   public:
    long long maximumBeauty(vector<int>& flowers,
                            long long newFlowers,
                            int target,
                            int full,
                            int partial) {
        int mi = target, l = flowers.size();
        long long ans = 0, delta = 0;
        for (int i : flowers) {
            if (i < target) {
                delta += target - i;
            }
            mi = min(i, mi);
        }
        if (newFlowers >= delta) {
            ans = (long long)full * l;
            if (mi < target) {
                ans = max(ans, (long long)full * (l - 1) +
                                   (long long)partial * (target - 1));
            }
            return ans;
        }
        int cnt = 0;
        sort(flowers.begin(), flowers.end());
        vector<long long> a(l);
        a[0] = 0;
        for (int i = 1; i < l; i++) {
            a[i] = a[i - 1] + i * (flowers[i] - flowers[i - 1]);
        }
        auto it = upper_bound(a.begin(), a.end(), newFlowers);
        int fs = it - a.begin();
        long long lw = min((long long)target - 1,
                           flowers[fs - 1] + (newFlowers - a[fs - 1]) / fs);
        ans = max(ans, (long long)cnt * full + (long long)lw * partial);
        for (int i = l - 1; i > 0; i--) {
            if (flowers[i] >= target)
                cnt++;
            else if (newFlowers >= (target - flowers[i])) {
                newFlowers -= (target - flowers[i]);
                cnt++;
            } else
                break;
            auto it = upper_bound(a.begin(), a.end(), newFlowers);
            int fs = min((int)(it - a.begin()), i);
            long long lw = min((long long)target - 1,
                               flowers[fs - 1] + (newFlowers - a[fs - 1]) / fs);
            ans = max(ans, (long long)cnt * full + (long long)lw * partial);
        }
        return ans;
    }
};