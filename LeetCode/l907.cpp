class Solution {
   public:
    int sumSubarrayMins(vector<int>& arr) {
        int l = arr.size();
        vector<int> v, p, li(l), ri(l);
        v.push_back(0), p.push_back(-1);
        for (int i = 0; i < l; i++) {
            while (arr[i] < v.back()) {
                v.pop_back();
                p.pop_back();
            }
            li[i] = p.back();
            p.push_back(i);
            v.push_back(arr[i]);
        }
        p.clear();
        v.clear();
        p.push_back(l), v.push_back(0);
        for (int i = l - 1; i >= 0; i--) {
            while (arr[i] <= v.back()) {
                v.pop_back();
                p.pop_back();
            }
            ri[i] = p.back();
            p.push_back(i);
            v.push_back(arr[i]);
        }
        long long ans = 0, MOD = 1e9 + 7;
        for (int i = 0; i < l; i++) {
            ans += (long long)(arr[i]) * (ri[i] - i) * (i - li[i]);
            ans %= MOD;
        }
        return ans;
    }
};