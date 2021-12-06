class Solution {
   public:
    int minimumDeletions(vector<int>& nums) {
        int mi = 0x3f3f3f3f, ma = -0x3f3f3f3f, ip = -1, ap = -1,
            l = nums.size();
        for (int i = 0; i < l; i++) {
            if (nums[i] > ma) {
                ma = nums[i];
                ap = i;
            }
            if (nums[i] < mi) {
                mi = nums[i];
                ip = i;
            }
        }
        if (ip < ap)
            swap(ap, ip);
        if (ip == ap)
            return min(ip + 1, l - ip);
        return min({ip + 1, l - ap, ap + 1 + l - ip});
    }
};