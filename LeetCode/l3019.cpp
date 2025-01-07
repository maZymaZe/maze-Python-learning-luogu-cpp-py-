class Solution {
   public:
    int countKeyChanges(string s) {
        int l = s.size(), ans = 0;
        if (s[0] >= 'A' && s[0] <= 'Z')
            s[0] += 'a' - 'A';
        for (int i = 1; i < l; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
            if (s[i] != s[i - 1])
                ans++;
        }
        return ans;
    }
};