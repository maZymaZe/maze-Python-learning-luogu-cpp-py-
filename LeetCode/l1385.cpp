class Solution {
   public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0, tt;
        for (int i : arr1) {
            tt = 0x3f3f3f3f;
            auto p = lower_bound(arr2.begin(), arr2.end(), i);
            if (p != arr2.end()) {
                tt = min(tt, *p - i);
            }
            p = upper_bound(arr2.begin(), arr2.end(), i);
            if (p != arr2.begin()) {
                --p;
                tt = min(tt, i - *p);
            }
            if (tt > d)
                cnt++;
        }
        return cnt;
    }
};