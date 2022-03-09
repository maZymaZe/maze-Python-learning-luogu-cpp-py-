class Solution {
   public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int l = fronts.size();
        int cnt[2002] = {0};
        for (int i = 0; i < l; i++) {
            if (fronts[i] == backs[i])
                cnt[fronts[i]] += 4;
            else {
                cnt[fronts[i]] |= 1;
                cnt[backs[i]] |= 1;
            }
        }
        for (int i = 0; i <= 2000; i++) {
            if (cnt[i] > 0 && cnt[i] < 4)
                return i;
        }
        return 0;
    }
};