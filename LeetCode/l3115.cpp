class Solution {
   public:
    int maximumPrimeDifference(vector<int>& nums) {
        int isp[102] = {0};
        for (int i = 2; i < 101; i++) {
            if (isp[i] == 0) {
                isp[i] = 1;
                for (int j = 2 * i; j < 101; j += i)
                    isp[j] = 2;
            }
        }
        int l = nums.size();
        int ma = 0, mi = l;
        for (int i = 0; i < l; i++) {
            if (isp[nums[i]] == 1) {
                ma = i;
                mi = min(mi, i);
            }
        }
        return ma - mi;
    }
};