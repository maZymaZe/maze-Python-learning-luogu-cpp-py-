class Solution {
   public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int l = maxHeights.size();
        vector<long long> la(l), ra(l);
        vector<int> sp, sv;
        sp.push_back(0), sv.push_back(0);
        long long sum = 0;
        for (int i = 0; i < l; i++) {
            int j = sv.size() - 1;
            while (maxHeights[i] <= sv[j]) {
                sum -= (long long)sv[j] * (sp[j] - sp[j - 1]);
                sv.pop_back(), sp.pop_back();
                j--;
            }
            sum += (long long)maxHeights[i] * (i + 1 - sp[j]);
            la[i] = sum;
            sv.push_back(maxHeights[i]);
            sp.push_back(i + 1);
        }
        sv.clear(), sp.clear();
        sv.push_back(0), sp.push_back(l + 1);
        sum = 0;
        for (int i = l - 1; i >= 0; i--) {
            int j = sv.size() - 1;
            while (maxHeights[i] <= sv[j]) {
                sum -= (long long)sv[j] * (sp[j - 1] - sp[j]);
                sv.pop_back(), sp.pop_back();
                j--;
            }
            sum += (long long)maxHeights[i] * (sp[j] - i - 1);
            ra[i] = sum;
            sv.push_back(maxHeights[i]);
            sp.push_back(i + 1);
        }
        long long ans = 0;
        for (int i = 0; i < l; i++) {
            ans = max(ans, la[i] + ra[i] - maxHeights[i]);
        }
        return ans;
    }
};