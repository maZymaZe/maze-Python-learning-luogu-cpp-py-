class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        long long ans = 0;
        vector<unordered_map<long long, int>> cnt(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long delta = (long long)A[i] - A[j];
                int sum = 0;
                if (cnt[j].count(delta))
                    sum = cnt[j][delta];
                cnt[i][delta] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};