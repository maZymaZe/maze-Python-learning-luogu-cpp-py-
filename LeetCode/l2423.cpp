class Solution {
   public:
    bool equalFrequency(string word) {
        int charCount[26] = {0};
        for (char c : word) {
            charCount[c - 'a']++;
        }
        unordered_map<int, int> freqCount;
        for (int c : charCount) {
            if (c > 0) {
                freqCount[c]++;
            }
        }
        for (int c : charCount) {
            if (c == 0) {
                continue;
            }
            freqCount[c]--;
            if (freqCount[c] == 0) {
                freqCount.erase(c);
            }
            if (c - 1 > 0) {
                freqCount[c - 1]++;
            }
            if (freqCount.size() == 1) {
                return true;
            }
            if (c - 1 > 0) {
                freqCount[c - 1]--;
                if (freqCount[c - 1] == 0) {
                    freqCount.erase(c - 1);
                }
            }
            freqCount[c]++;
        }
        return false;
    }
};
