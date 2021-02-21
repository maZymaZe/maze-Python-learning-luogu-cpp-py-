class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = nums.size(), r = 0, ans = 0;
        deque<int> ma, mi, pma, pmi;
        for (int i = 0; i < l; i++) {
            if (!ma.empty() && pma.front() < i) {
                ma.pop_front();
                pma.pop_front();
            }
            if (!mi.empty() && pmi.front() < i) {
                mi.pop_front();
                pmi.pop_front();
            }
            while (r < l && (mi.empty() || ma.front() - mi.front() <= limit)) {
                while (!ma.empty() && nums[r] >= ma.back()) {
                    ma.pop_back();
                    pma.pop_back();
                }
                ma.push_back(nums[r]);
                pma.push_back(r);
                while (!mi.empty() && nums[r] <= mi.back()) {
                    mi.pop_back();
                    pmi.pop_back();
                }
                mi.push_back(nums[r]);
                pmi.push_back(r);
                r++;
            }

            if (r == l) {
                if (ma.front() - mi.front() <= limit) {
                    ans = max(ans, r - i);
                } else {
                    ans = max(ans, r - i - 1);
                }
                break;
            } else {
                ans = max(ans, r - i - 1);
            }
        }
        return ans;
    }
};