class Solution {
   public:
    int edgeScore(vector<int>& edges) {
        int l = edges.size();
        vector<long long> ans(l);
        for (int i = 0; i < l; i++) {
            ans[edges[i]] += i;
        }
        long long ma = ans[0];
        int p = 0;
        for (int i = 1; i < l; i++) {
            if (ans[i] > ma) {
                ma = ans[i];
                p = i;
            }
        }
        return p;
    }
};