class Solution {
   public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, ed;
        for (int i : nums) {
            int c = cnt[i] + 1;
            cnt[i] = c;
        }
        for (int i : nums) {
            int c = cnt[i];
            if (c > 0) {
                int pe = ed[i - 1];
                if (pe > 0) {
                    cnt[i] = c - 1;
                    ed[i - 1] = pe - 1;
                    ed[i] = ed[i] + 1;
                } else {
                    int c1 = cnt[i + 1], c2 = cnt[i + 2];
                    if (c1 > 0 && c2 > 0) {
                        cnt[i] = cnt[i] - 1;
                        cnt[i + 1] = cnt[i + 1] - 1;
                        cnt[i + 2] = cnt[i + 2] - 1;
                        ed[i + 2] = ed[i + 2] + 1;
                    } else {
                        return false
                    }
                }
            }
        }
        return true;
    }
};