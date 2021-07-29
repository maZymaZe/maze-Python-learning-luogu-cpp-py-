class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int pmax = -1, nmax = 1, ans = 0x80000000;
        int p = 0, l = nums.size();
        while (p < l && nums[p] == 0)
            p++, ans = 0;
        if (p == l)
            return 0;
        int pf = 0, nf = 0, zf = 0;
        while (p < l) {
            if (zf == 0) {
                zf = 1;
                if (nums[p] > 0) {
                    pf = 1;
                    pmax = nums[p];
                    ans = max(ans, pmax);
                } else {
                    nf = 1;
                    nmax = nums[p];
                    ans = max(ans, nmax);
                }
            } else {
                if (nums[p] == 0) {
                    ans = max(ans, 0);
                    while (p < l && nums[p] == 0) {
                        p++;
                    }
                    zf = 0, pf = nf = 0;
                    p--;
                } else if (nums[p] > 0) {
                    if (pf) {
                        pmax = nums[p] * pmax;
                        ans = max(ans, pmax);
                    } else {
                        pf = 1;
                        pmax = nums[p];
                        ans = max(ans, pmax);
                    }
                    if (nf) {
                        nmax = nums[p] * nmax;
                        ans = max(ans, nmax);
                    }
                } else {
                    int tnmax = nmax, tpmax = pmax, tnf = nf, tpf = pf;

                    if (nf) {
                        tpf = 1;
                        tpmax = nums[p] * nmax;
                        ans = max(ans, tpmax);
                        if (!pf) {
                            tnf = 1;
                            tnmax = nums[p];
                            ans = max(ans, tnmax);
                        }
                    } else {
                        tnf = 1;
                        tnmax = nums[p];
                        ans = max(ans, tnmax);
                        tpf = 0;
                    }
                    if (pf) {
                        tnf = 1;
                        tnmax = nums[p] * pmax;
                        ans = max(ans, tnmax);
                    }
                    nf = tnf, pf = tpf;
                    pmax = tpmax, nmax = tnmax;
                }
            }
            p++;
        }
        return ans;
    }
};