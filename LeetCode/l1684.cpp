class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for (auto c : allowed) {
            mask |= 1 << (c - 'a');
        }
        int res = 0;
        for (auto &&word : words) {
            int mask1 = 0;
            for (auto c : word) {
                mask1 |= 1 << (c - 'a');
            }
            if ((mask1 | mask) == mask) {
                res++;
            }
        }
        return res;
    }
};
