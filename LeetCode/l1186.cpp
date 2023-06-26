class Solution {
   public:
    int maximumSum(vector<int>& arr) {
        vector<int> ml, mr;
        int ans = -1000000;
        int tot = 0, l = arr.size(), mi = min(0, arr[0]);
        ml.resize(l);
        mr.resize(l);
        for (int i = 0; i < l; i++) {
            tot += arr[i];
            if (i)
                ml[i] = max(arr[i], tot - mi);
            else
                ml[i] = arr[0];
            ans = max(ans, ml[i]);
            mi = min(mi, tot);
        }
        tot = 0, mi = min(0, arr[l - 1]);
        for (int i = l - 1; i >= 0; i--) {
            tot += arr[i];
            if (i == l - 1) {
                mr[i] = arr[i];
            } else {
                mr[i] = max(arr[i], tot - mi);
            }
            mi = min(mi, tot);
        }
        for (int i = 1; i < l - 1; i++) {
            ans = max(ans, ml[i - 1] + mr[i + 1]);
        }
        return ans;
    }
};