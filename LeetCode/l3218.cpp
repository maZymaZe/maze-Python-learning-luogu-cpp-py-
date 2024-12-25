class Solution {
   public:
    int minimumCost(int m,
                    int n,
                    vector<int>& horizontalCut,
                    vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        int toth = 1, totv = 1;

        int ans = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty() ||
                !horizontalCut.empty() &&
                    horizontalCut.back() > verticalCut.back()) {
                ans += horizontalCut.back() * toth;
                horizontalCut.pop_back();
                totv++;
            } else {
                ans += verticalCut.back() * totv;
                verticalCut.pop_back();
                toth++;
            }
        }
        return ans;
    }
};