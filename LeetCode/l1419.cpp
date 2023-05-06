class Solution {
   public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c[4] = {0}, l = croakOfFrogs.size(), ta = 0, ans = 0;
        for (int i = 0; i < l; i++) {
            if (croakOfFrogs[i] == 'c') {
                ta++;
                c[0]++;
                ans = max(ta, ans);
            } else if (croakOfFrogs[i] == 'r') {
                if (c[0]) {
                    c[0]--;
                    c[1]++;
                } else
                    return -1;
            } else if (croakOfFrogs[i] == 'o') {
                if (c[1]) {
                    c[1]--;
                    c[2]++;
                } else
                    return -1;
            } else if (croakOfFrogs[i] == 'a') {
                if (c[2]) {
                    c[2]--;
                    c[3]++;
                } else
                    return -1;
            } else if (croakOfFrogs[i] == 'k') {
                if (c[3]) {
                    c[3]--;
                    ta--;
                } else
                    return -1;
            }
        }
        if (c[0] || c[1] || c[2] || c[3])
            return -1;
        return ans;
    }
};