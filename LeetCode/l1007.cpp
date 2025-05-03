class Solution {
   public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a[4] = {0};
        int n = tops.size();
        a[2] = a[3] = 1;
        int ok = 15;
        for (int i = 1; i < n; i++) {
            if (tops[i] == tops[0]) {
            } else if (bottoms[i] == tops[0]) {
                a[0]++;
            } else
                ok &= (15 - 1);

            if (bottoms[i] == bottoms[0]) {
            } else if (tops[i] == bottoms[0]) {
                a[1]++;
            } else
                ok &= (15 - 2);

            if (tops[i] == bottoms[0]) {
            } else if (bottoms[i] == bottoms[0]) {
                a[2]++;
            } else
                ok &= (15 - 4);
            if (bottoms[i] == tops[0]) {
            } else if (tops[i] == tops[0]) {
                a[3]++;
            } else
                ok &= (15 - 8);
        }
        if (ok == 0)
            return -1;
        int ans = n;
        for (int i = 0; i < 4; i++) {
            if (ok & (1 << i)) {
                ans = min(ans, a[i]);
            }
        }
        return ans;
    }
};