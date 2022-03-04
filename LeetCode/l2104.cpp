class Solution {
   public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0, pre = 0;
        int l = nums.size();
        vector<int> ma, mi, ap, ip;
        if (l == 0)
            return 0;
        ma.push_back(0x3f3f3f3f), mi.push_back(-0x3f3f3f3f);
        ap.push_back(-1), ip.push_back(-1);
        ma.push_back(nums[0]), mi.push_back(nums[0]);
        ap.push_back(0), ip.push_back(0);
        for (int i = 1; i < l; i++) {
            int bk = ma.size() - 1;
            while (nums[i] >= ma[bk]) {
                pre += (long long)(ap[bk] - ap[bk - 1]) * (nums[i] - ma[bk]);
                ap.pop_back(), ma.pop_back();
                bk--;
            }
            ap.push_back(i), ma.push_back(nums[i]);

            bk = mi.size() - 1;
            while (nums[i] <= mi[bk]) {
                pre += (long long)(ip[bk] - ip[bk - 1]) * (mi[bk] - nums[i]);
                ip.pop_back(), mi.pop_back();
                bk--;
            }
            ip.push_back(i), mi.push_back(nums[i]);
            ans += pre;
        }
        return ans;
    }
};