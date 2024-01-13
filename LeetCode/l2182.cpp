class Solution {
   public:
    string repeatLimitedString(string s, int repeatLimit) {
        int c[26] = {0};
        string ans;
        for (char t : s)
            c[t - 'a']++;
        for (int i = 25; i >= 0; i--) {
            int pad = 0;
            while (c[i] > repeatLimit) {
                ans += string(repeatLimit, 'a' + i);
                pad = -1;
                for (int j = i - 1; j >= 0; j--) {
                    if (c[j]) {
                        pad = j;
                        break;
                    }
                }
                if (pad == -1)
                    return ans;
                c[pad]--;
                ans += (char)(pad + 'a');
                c[i] -= repeatLimit;
            }
            if (c[i]) {
                ans += string(c[i], 'a' + i);
                c[i] = 0;
            }
        }
        return ans;
    }
};