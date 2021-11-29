class Solution {
   public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(drinks.begin(), drinks.end());
        long long ans = 0, MOD = 1e9 + 7;
        for (int i : staple) {
            if (i <= x) {
                ans = (ans + (upper_bound(drinks.begin(), drinks.end(), x - i) -
                              drinks.begin())) %
                      MOD;
            }
        }
        return ans;
    }
};