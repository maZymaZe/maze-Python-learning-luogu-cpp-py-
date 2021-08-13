class Solution {
   public:
    int unhappyFriends(int n,
                       vector<vector<int>>& preferences,
                       vector<vector<int>>& pairs) {
        vector<vector<int>> fp(n, vector<int>(n));
        int l = preferences.size(), m = preferences[0].size();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) {
                fp[i][preferences[i][j]] = j;
            }
        }
        int pr = pairs.size();
        vector<int> op(n);
        for (int i = 0; i < pr; i++) {
            op[pairs[i][0]] = pairs[i][1];
            op[pairs[i][1]] = pairs[i][0];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i && j != op[i]) {
                    if (fp[i][j] < fp[i][op[i]] && fp[j][i] < fp[j][op[j]]) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};