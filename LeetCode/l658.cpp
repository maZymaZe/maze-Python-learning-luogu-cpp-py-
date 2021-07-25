class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        auto p = it;
        int f1 = 1, f2 = 1;
        if (p != arr.begin())
            p--;
        else
            f1 = 0;
        if (it == arr.end())
            f2 = 0;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            if (f1 && f2) {
                if (x - *p <= *it - x) {
                    ans[i] = *p;
                    if (p == arr.begin())
                        f1 = 0;
                    else
                        --p;
                } else {
                    ans[i] = *it;
                    it++;
                    if (it == arr.end())
                        f2 = 0;
                }
            } else if (f1) {
                ans[i] = *p;
                if (p == arr.begin())
                    f1 = 0;
                else
                    --p;
            } else if (f2) {
                ans[i] = *it;
                it++;
                if (it == arr.end())
                    f2 = 0;
            } else {
                return {};
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};