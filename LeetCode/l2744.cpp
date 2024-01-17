class Solution {
   public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> w;
        int ans = 0;
        for (string s : words) {
            if (w.count(s))
                ans++;
            else {
                reverse(s.begin(), s.end());
                w.insert(s);
            }
        }
        return ans;
    }
};