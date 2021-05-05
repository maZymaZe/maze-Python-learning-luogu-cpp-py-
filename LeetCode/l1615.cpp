class Solution {
   public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n);
        vector<vector<int>> mp(n, vector<int>(n));
        for (auto& i : roads) {
            mp[i[0]][i[1]] = 1;
            mp[i[1]][i[0]] = 1;
            cnt[i[0]]++;
            cnt[i[1]]++;
        }
        int mxv = 0, cmxv = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mxv) {
                mxv = cnt[i];
                cmxv = 1;
            } else if (cnt[i] == mxv) {
                cmxv++;
            }
        }
        if (cmxv > 1) {
            vector<int> mxp;
            for (int i = 0; i < n; i++) {
                if (cnt[i] == mxv) {
                    mxp.push_back(i);
                }
            }
            int l = mxp.size();
            for (int i = 0; i < l; i++) {
                for (int j = i + 1; j < l; j++) {
                    if (mp[mxp[i]][mxp[j]] == 0)
                        return mxv + mxv;
                }
            }
            return mxv + mxv - 1;
        }
        int smxv = 0, csmxv = 0, mxpp, smxp;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > smxv && cnt[i] != mxv) {
                smxv = cnt[i];
                smxp = i;
                csmxv = 1;
            } else if (cnt[i] == smxv) {
                csmxv++;
            } else if (cnt[i] == mxv) {
                mxpp = i;
            }
        }
        if (csmxv == 1)
            return mxv + smxv - (mp[mxpp][smxp]);
        vector<int> smxpp;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == smxv)
                smxpp.push_back(i);
        }
        for (int i = 0; i < csmxv; i++) {
            if (mp[mxpp][smxpp[i]] == 0)
                return mxv + smxv;
        }
        return mxv + smxv - 1;
    }
};