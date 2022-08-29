class Solution {
   public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int l = birth.size();
        int t[102] = {0}, ans = 0, c = 0, y;
        for (int i = 0; i < l; i++) {
            t[birth[i] - 1900]++;
            t[min(101, death[i] - 1900 + 1)]--;
        }
        for (int i = 0; i < 102; i++) {
            c += t[i];
            if (c > ans) {
                ans = c;
                y = i + 1900;
            }
        }
        return y;
    }
};