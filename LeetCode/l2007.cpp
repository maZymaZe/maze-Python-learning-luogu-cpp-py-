class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        queue<int> q;
        vector<int> ans;
        int l = changed.size();
        for (int i = l - 1; i >= 0; i--) {
            if (!q.empty() && changed[i] == q.front()) {
                q.pop();
                ans.push_back(changed[i]);
            } else if (changed[i] % 2)
                return {};
            else
                q.push(changed[i] / 2);
        }
        if (!q.empty())
            return {};
        return ans;
    }
};