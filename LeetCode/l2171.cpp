class Solution {
   public:
    long long minimumRemoval(vector<int>& beans) {
        long long tot = 0, ans = 0x7FFFFFFFFFFFFFFFll;
        int l = beans.size();
        sort(beans.begin(), beans.end());
        for (int i = 0; i < l; i++)
            tot += beans[i];
        for (int i = 0; i < l; i++) {
            ans = min(ans, tot - (long long)beans[i] * (l - i));
        }
        return ans;
    }
};