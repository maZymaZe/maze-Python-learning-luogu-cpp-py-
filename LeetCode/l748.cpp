class Solution {
   public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int c1[26] = {0}, c2[26] = {0}, ml = 0x3f3f3f3f, idx = -1;
        int l = licensePlate.size();
        for (int i = 0; i < l; i++) {
            if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z') {
                c1[licensePlate[i] - 'a']++;
            }
            if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') {
                c1[licensePlate[i] - 'A']++;
            }
        }
        int len = words.size();
        for (int i = 0; i < len; i++) {
            memset(c2, 0, sizeof(c2));
            l = words[i].size();
            for (int j = 0; j < l; j++) {
                c2[words[i][j] - 'a']++;
            }
            int f = 1;
            for (int j = 0; j < 26; j++) {
                if (c1[j] > c2[j]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                if (l < ml)
                    idx = i, ml = l;
            }
        }
        return words[idx];
    }
};