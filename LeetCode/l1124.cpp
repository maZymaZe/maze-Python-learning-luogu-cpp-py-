class Solution {
   public:
    int longestWPI(vector<int>& hours) {
        int l = hours.size(), t = 0;
        vector<int> s(l + 1);
        s[0] = 0;
        for (int i = 0; i < l; i++) {
            if (hours[i] > 8)
                t++;
            else
                t--;
            s[i + 1] = t;
        }
        unordered_map<int, int> mp1, mp2;
        for (int i = 0; i <= l; i++) {
            mp2[s[i]] = i;
            if (!mp1.count(s[i]))
                mp1[s[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i <= l; i++) {
            if (s[i] > 0)
                ans = max(ans, i);
            else {
                if (mp2[s[i]] == i) {
                    if (mp1.count(s[i] - 1)) {
                        ans = max(mp2[s[i]] - mp1[s[i] - 1],ans);
                    }
                }
            }
        }
        return ans;
    }
};