class Solution {
   public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), ans = 0, left = 0;
        while (left + 2 < n) {
            int right = left + 1;
            if (A[left] < A[left + 1]) {
                while (right + 1 < n && A[right] < A[right + 1]) {
                    right++;
                }
                if (right + 1 < n && A[right] > A[right + 1]) {
                    while (right + 1 < n && A[right] > A[right + 1]) {
                        right++;
                    }
                    ans = max(ans, right - left + 1);
                } else
                    right++;
            }
            left = right;
        }
        return ans;
    }
};