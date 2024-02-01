struct PR {
    int c, id;
    bool operator<(const PR& x) { return c > x.c; }
};
class Solution {
   public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int l = aliceValues.size();
        vector<PR> cc;
        for (int i = 0; i < l; i++)
            cc.push_back({aliceValues[i] + bobValues[i], i});
        sort(cc.begin(), cc.end());
        int t1 = 0, t2 = 0;
        for (int i = 0; i < l; i++) {
            if (i & 1)
                t2 += bobValues[cc[i].id];
            else
                t1 += aliceValues[cc[i].id];
        }
        int tot = t1 - t2;
        if (tot > 0)
            return 1;
        else if (tot == 0)
            return 0;
        return -1;
    }
};