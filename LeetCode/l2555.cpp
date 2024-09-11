class Solution {
   public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int l = prizePositions.size();
        int lm = 0, ans = 0, rt, tlm;
        for (int i = 0; i < l; i++) {
            tlm = (int)(prizePositions.begin() + i -
                        lower_bound(prizePositions.begin(),
                                    prizePositions.begin() + i,
                                    prizePositions[i] - k));
            rt = (upper_bound(prizePositions.begin() + i, prizePositions.end(),
                              prizePositions[i] + k) -
                  (prizePositions.begin() + i));
            ans = max(ans, lm + rt);
            ans = max(ans, tlm + rt);
            lm = max(lm, tlm + 1);
        }
        return ans;
    }
};