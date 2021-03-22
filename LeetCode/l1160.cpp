class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        int cu[26] = {0}, ans = 0;
        for (char i : chars) {
            cu[i - 'a']++;
        }
        for (string& s : words) {
            int ct[26] = {0};
            for (char i : s) {
                ct[i - 'a']++;
            }
            int t = s.size();
            for (int i = 0; i < 26; i++) {
                if (ct[i] > cu[i]) {
                    t = 0;
                    break;
                }
            }
            ans += t;
        }
        return ans;
    }
};