class Solution {
   public:
    string alienOrder(vector<string>& words) {
        int vis[26] = {0}, indegree[26] = {0};
        int bm[26][26] = {0};
        int l = words.size();
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                int n = words[j].size(), m = words[i].size();
                if (m > n && words[i].substr(0, n) == words[j])
                    return "";
                int x = min(n, m);
                for (int k = 0; k < x; k++) {
                    if (words[j][k] != words[i][k]) {
                        bm[words[i][k] - 'a'][words[j][k] - 'a'] = 1;
                        break;
                    }
                }
            }
        }
        for (auto& x : words) {
            for (auto& y : x) {
                vis[y - 'a'] = 1;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++)
                indegree[i] += bm[j][i];
        }
        string ans;
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (vis[i] && indegree[i] == 0) {
                q.push(i);
                ans += i + 'a';
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                if (vis[i] && bm[x][i]) {
                    indegree[i]--;
                    if (indegree[i] == 0) {
                        q.push(i);
                        ans += i + 'a';
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += vis[i];
        if (ans.size() == cnt)
            return ans;
        return "";
    }
};