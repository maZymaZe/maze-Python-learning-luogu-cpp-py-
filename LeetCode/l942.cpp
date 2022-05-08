class Solution {
   public:
    vector<int> diStringMatch(string s) {
        int l = s.size(), mi = 0, mi2;
        for (char i : s) {
            if (i == 'D')
                mi++;
        }
        vector<int> ans;
        ans.push_back(mi);
        mi2 = mi;
        for (char i : s) {
            if (i == 'D')
                ans.push_back(--mi);
            else
                ans.push_back(++mi2);
        }
        return ans;
    }
};