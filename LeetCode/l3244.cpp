class Solution {
   public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        int cur = n - 1;
        vector<int> ans, nx(n);
        for (int i = 0; i < n - 1; i++)
            nx[i] = i + 1;
        for (const auto& q : queries) {
            int k = nx[q[0]];
            nx[q[0]] = q[1];
            while (k != -1 && k < q[1]) {
                int t = nx[k];
                nx[k] = -1;
                k = t;
                cur--;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};