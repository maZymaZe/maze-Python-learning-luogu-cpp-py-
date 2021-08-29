class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int l = arr.size();
        long long ans = 0;
        vector<long long> ps(l + 1);
        ps[0] = 0;
        for (int i = 1; i <= l; i++)
            ps[i] = ps[i - 1] + arr[i - 1];
        for (int i = 0; i <= l; i++) {
            for (int j = 0; j < i; j++) {
                if ((i - j) & 1)
                    ans += ps[i] - ps[j];
            }
        }
        return (int)ans;
    }
};