class Solution {
   public:
    vector<int> constructArr(vector<int>& a) {
        int l = a.size();
        vector<int> ll(l + 2), rr(l + 2), ans(l);
        ll[0] = 1;
        for (int i = 1; i <= l; i++)
            ll[i] = ll[i - 1] * a[i - 1];
        rr[l] = 1;
        for (int i = l - 1; i >= 0; i--)
            rr[i] = rr[i + 1] * a[i];
        for (int i = 0; i < l; i++)
            ans[i] = ll[i] * rr[i + 1];
        return ans;
    }
};