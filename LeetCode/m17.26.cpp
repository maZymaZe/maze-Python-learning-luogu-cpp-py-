class Solution {
   public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        unordered_map<int, vector<int>> mp1;
        for (int i = 0; i < docs.size(); i++) {
            for (auto& x : docs[i]) {
                mp1[x].push_back(i);
            }
        }
        unordered_map<int, unordered_map<int, int>> mp2;
        for (auto& x : mp1) {
            auto& ids = x.second;
            for (int i = 0; i + 1 < ids.size(); i++) {
                for (int j = i + 1; j < ids.size(); j++) {
                    mp2[ids[i]][ids[j]]++;
                }
            }
        }
        vector<string> res;
        char tmp[256];
        for (auto& x : mp2) {
            int id1 = x.first;
            for (auto& y : x.second) {
                int id2 = y.first;
                double s = (double)y.second /
                           (docs[id1].size() + docs[id2].size() - y.second);
                sprintf(tmp, "%d,%d: %0.4lf", id1, id2, s + 1e-9);
                res.push_back(tmp);
            }
        }
        return res;
    }
};