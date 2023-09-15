class Solution {
   public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        int l = gem.size();
        for (auto& v : operations) {
            int x = gem[v[0]] / 2;
            gem[v[0]] -= x;
            gem[v[1]] += x;
        }
        int ma = gem[0], mi = gem[0];
        for (int i : gem)
            ma = max(ma, i), mi = min(mi, i);
        return ma - mi;
    }
};