class Solution {
   public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum & 1)
            return {};
        long long tot = 0, p = 0;
        while (tot < finalSum) {
            p += 2;
            tot += p;
        }
        vector<long long> ans;
        for (int i = 2; i <= p; i += 2) {
            if (i != tot - finalSum) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};