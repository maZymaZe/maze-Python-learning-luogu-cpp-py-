class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0, l = 1, r = 1e9 + 10, mid;
        while (l < r) {
            mid = (l + r) / 2;
            sum = 0;
            for (int i : piles) {
                sum += (mid - 1 + i) / mid;
            }
            if (sum > h)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};