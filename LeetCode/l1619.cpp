class Solution {
   public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int l = arr.size();
        int x = l / 20;
        long long tot = 0;
        for (int i = x; i < l - x; i++)
            tot += arr[i];
        return 1.0 * tot / x / 18;
    }
};