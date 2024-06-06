class Solution {
   public:
    long long minimumSteps(string s) {
        long long t = 0, p = 0;
        int l = s.size();
        for (int j = 0; j < l; j++) {
            if (s[j] - '0' == 0) {
                t += (j - p);
                p++;
            }
        }
        return t;
    }
};