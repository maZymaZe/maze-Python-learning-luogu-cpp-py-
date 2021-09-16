class Solution {
   public:
    int maxSubarraySumCircular(vector<int>& A) {
        int l = A.size(), tot = 0, c = 0;

        int mmx = -1000000, ppre = 0;
        for (int i = 0; i < l; i++) {
            ppre = max(0, ppre) + A[i];
            mmx = max(mmx, ppre);
        }

        for (int i = 0; i < l; i++) {
            if (A[i] <= 0)
                c++;
            tot += A[i], A[i] = -A[i];
        }
        if (c == l) {
            int t = 1000000;
            for (int i = 0; i < l; i++)
                t = min(t, A[i]);
            return -t;
        }
        int mx = 0, pre = 0;
        for (int i = 0; i < l; i++) {
            pre = max(0, pre) + A[i];
            mx = max(mx, pre);
        }
        return max(tot + mx, mmx);
    }
};