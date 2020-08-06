class Solution {
   public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> ps(n);
        unordered_map<string, int> note;
        for (int i = 0; i < n; i++) {
            note[words[i]] = i;
            string tmp("#");
            for (auto c : words[i]) {
                tmp += c;
                tmp += "#";
            }
            ps[i].resize(tmp.size(), 1);
            int mx = 0, mid = 0, l = tmp.size();
            for (int j = 1; j < l; j++) {
                if (j < mx)
                    ps[i][j] = min(ps[i][2 * mid - j], mx - j + 1);
                int left = j - ps[i][j], right = j + ps[i][j];
                while (left >= 0 && right < tmp.size() &&
                       tmp[left] == tmp[right]) {
                    ps[i][j]++;
                    left--;
                    right++;
                }
                if (right - 1 > mx) {
                    mx = right - 1;
                    mid = j;
                }
            }
        }
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < ps[i].size(); j++) {
                if (j + 1 <= ps[i][j]) {
                    string ma = words[i].substr(j, words[i].size());
                    reverse(ma.begin(), ma.end());
                    if (note.count(ma) && note[ma] != i) {
                        ans.insert({note[ma], i});
                    }
                }
                if (j + ps[i][j] == ps[i].size()) {
                    string ma = words[i].substr(0, j - words[i].size());
                    reverse(ma.begin(), ma.end());
                    if (note.count(ma) && note[ma] != i) {
                        ans.insert({i, note[ma]});
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for (auto x : ans)
            ret.push_back(x);
        return ret;
    }
};