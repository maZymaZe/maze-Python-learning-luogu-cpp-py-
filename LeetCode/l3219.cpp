class Solution {
   public:
    long long minimumCost(int m,
                          int n,
                          vector<int>& horizontalCut,
                          vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        int toth = 1, totv = 1;

        long long ans = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty() ||
                !horizontalCut.empty() &&
                    horizontalCut.back() > verticalCut.back()) {
                ans += (long long)horizontalCut.back() * toth;
                horizontalCut.pop_back();
                totv++;
            } else {
                ans += (long long)verticalCut.back() * totv;
                verticalCut.pop_back();
                toth++;
            }
        }
        return ans;
    }
};