class Solution {
   public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return 2 * rewardValues[n - 1] - 1;
        }
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < rewardValues[i]) {
                f1[j] = f0[j];
                j++;
            }
            f0 |= f1 << rewardValues[i];
        }
        int res = 0;
        for (int i = 0; i < f0.size(); i++) {
            if (f0[i]) {
                res = i;
            }
        }
        return res;
    }
};
