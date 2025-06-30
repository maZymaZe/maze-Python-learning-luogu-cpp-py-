class Solution {
   public:
    int possibleStringCount(string word) {
        int ans = 1, pre = word[0], l = word.size();
        for (int i = 1; i < l; i++) {
            if (word[i] == pre)
                ans++;
            pre = word[i];
        }
        return ans;
    }
};