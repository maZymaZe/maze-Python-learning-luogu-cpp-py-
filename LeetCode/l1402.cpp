class Solution {
   public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int tot = 0, ans = 0;
        for (int i : satisfaction) {
            tot += i;
            if (tot >= 0)
                ans += tot;
            else
                break;
        }
        return ans;
    }
};