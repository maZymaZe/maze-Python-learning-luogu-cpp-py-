class Solution {
   public:
    vector<string> findRelativeRanks(vector<int>& score) {
        auto x = score;
        int l = score.size();
        sort(x.begin(), x.end(), greater<int>());
        vector<string> ans;
        for (int i = 0; i < l; i++) {
            int idx =
                lower_bound(x.begin(), x.end(), score[i], greater<int>()) -
                x.begin() + 1;
            if (idx == 1)
                ans.push_back("Gold Medal");
            else if (idx == 2)
                ans.push_back("Silver Medal");
            else if (idx == 3)
                ans.push_back("Bronze Medal");
            else
                ans.push_back(to_string(idx));
        }
        return ans;
    }
};