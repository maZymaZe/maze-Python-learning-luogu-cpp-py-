struct pr {
    int v, pos;
    bool operator<(const pr& x) { return v < x.v; }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<pr> s;
        int n=T.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.back().v <= T[i]) s.pop_back();
            if (s.empty()) {
                s.push_back({T[i], i});
                ans[i] = 0;
            }
            else {
                ans[i]=s.back().pos-i;
                s.push_back({T[i], i});
            }
        }
        return ans;
    }
};