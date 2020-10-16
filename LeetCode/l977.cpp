class Solution {
   public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = A.size(), p, n;
        vector<int> ans;
        if (A[0] >= 0) {
            p = 0, n = -1;
        } else if (A[l - 1] < 0) {
            p = l, n = l - 1;
        } else {
            for (int i = 1; i < l; i++) {
                if (A[i] >= 0) {
                    p = i, n = i - 1;
                    break;
                }
            }
            while (p < l && n >= 0) {
                if (A[p] <= -A[n]) {
                    ans.push_back(A[p] * A[p]), p++;
                } else
                    ans.push_back(A[n] * A[n]), n--;
            }
        }
        while (p < l)
            ans.push_back(A[p] * A[p]), p++;
        while (n >= 0)
            ans.push_back(A[n] * A[n]), n--;
        return ans;
    }
};