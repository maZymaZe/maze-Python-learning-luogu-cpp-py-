class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> bf;
    int query;
    void dfs(int x) {
        int lim = sqrt(query);
        for (int i = x; i <= lim + 3; i++) {
            if (query % i == 0) {
                query /= i;
                bf.push_back(i);
                dfs(i);
                bf.pop_back();
                query *= i;
            }
        }
        if (query >= x) {
            bf.push_back(query);
            ans.push_back(bf);
            bf.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        query = n;
        int w = sqrt(n);
        for (int i = 2; i < w + 2; i++) {
            if (i == n)
                break;
            if (n % i == 0) {
                bf.push_back(i);
                query /= i;
                dfs(i);
                query *= i;
                bf.pop_back();
            }
        }
        return ans;
    }
};