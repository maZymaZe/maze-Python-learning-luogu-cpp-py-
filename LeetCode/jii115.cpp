class Solution {
   public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size(), indegree[10003] = {0};
        if (seqs.size() == 0)
            return false;
        set<int> nx[10003];
        for (auto& x : seqs) {
            int l = x.size();
            if (x[0] < 1 || x[0] > n)
                return false;
            for (int i = 1; i < l; i++) {
                if (x[i] < 1 || x[i] > n)
                    return false;
                if (!nx[x[i - 1]].count(x[i]))
                    indegree[x[i]]++;
                nx[x[i - 1]].insert(x[i]);
            }
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
        if (q.size() != 1)
            return false;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (!q.empty())
                return false;
            for (auto i : nx[x]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        if (ans.size() != n)
            return false;
        for (int i = 0; i < n; i++)
            if (ans[i] != org[i])
                return false;
        return true;
    }
};