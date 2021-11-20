class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp, u;
        for (int i : nums)
            if (!mp.count(i))
                mp.insert(i);
        int t, ans = 0, p, q;
        for (int i : nums)
            if (!u.count(i)) {
                t = 1;
                p = i + 1;
                q = i - 1;
                u.insert(i);
                while (mp.count(p)) {
                    u.insert(p);
                    p++;
                    t++;
                }
                while (mp.count(q)) {
                    u.insert(q);
                    q--;
                    t++;
                }
                ans = max(ans, t);
            }
        return ans;
    }
};