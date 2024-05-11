class Solution {
   public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int l = garbage.size(), c[3] = {0}, lc[3] = {0};
        for (int i = 0; i < l; i++) {
            for (char t : garbage[i]) {
                if (t == 'M') {
                    c[0]++, lc[0] = i;
                } else if (t == 'G') {
                    c[1]++, lc[1] = i;
                } else {
                    c[2]++, lc[2] = i;
                }
            }
        }
        int t = 0, ans = 0;
        for (int i = 0; i < l - 1; i++) {
            t += travel[i];
            for (int j = 0; j < 3; j++) {
                if (i + 1 == lc[j])
                    ans += t;
            }
        }
        for (int i = 0; i < 3; i++)
            ans += c[i];
        return ans;
    }
};