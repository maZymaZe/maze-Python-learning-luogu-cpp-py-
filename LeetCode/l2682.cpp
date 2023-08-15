class Solution {
   public:
    vector<int> circularGameLosers(int n, int k) {
        int v[59] = {0};
        v[1] = 1;
        int p = 1, t = k;
        while (1) {
            p = (p + t - 1) % n + 1;
            t += k;
            if (v[p])
                break;
            else
                v[p] = 1;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            if (!v[i])
                ans.push_back(i);
        return ans;
    }
};