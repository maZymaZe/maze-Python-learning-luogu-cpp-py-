class Solution {
   public:
    int calculateTime(string keyboard, string word) {
        int p = 0, pos[30] = {0}, ans = 0;
        for (int i = 0; i < 26; i++)
            pos[keyboard[i] - 'a'] = i;
        for (auto c : word) {
            ans += abs(pos[c - 'a'] - p);
            p = pos[c - 'a'];
        }
        return ans;
    }
};