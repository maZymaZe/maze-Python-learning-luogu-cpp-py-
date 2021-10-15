class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int l = words.size();
        vector<int> mk(l);
        for (int i = 0; i < l; i++) {
            for (auto c : words[i]) {
                mk[i] |= (1 << (c - 'a'));
            }
        }
        int ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if ((mk[j] & mk[i]) == 0) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};