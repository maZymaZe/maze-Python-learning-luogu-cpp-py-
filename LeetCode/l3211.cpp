class Solution {
   public:
    vector<string> ans;
    int N;
    void dfs(string& x) {
        if (x.size() == N) {
            ans.push_back(x);
            return;
        }
        if (x.empty() || x.back() != '0') {
            x.push_back('0');
            dfs(x);
            x.pop_back();
        }
        x.push_back('1');
        dfs(x);
        x.pop_back();
    }
    vector<string> validStrings(int n) {
        string x;
        N = n;
        dfs(x);
        return ans;
    }
};