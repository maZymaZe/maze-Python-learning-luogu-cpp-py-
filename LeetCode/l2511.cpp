class Solution {
   public:
    int captureForts(vector<int>& forts) {
        int ans = 0, pre = -1;
        for (int i = 0; i < forts.size(); i++) {
            if (forts[i] == 1 || forts[i] == -1) {
                if (pre >= 0 && forts[i] != forts[pre]) {
                    ans = max(ans, i - pre - 1);
                }
                pre = i;
            }
        }
        return ans;
    }
};
