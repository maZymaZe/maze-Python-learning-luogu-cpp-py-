class Solution {
   public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1, r = 1e18, mid;
        while (l < r) {
            mid = (l + r) / 2;
            long long tot = 0;
            for (int i : time) {
                tot += mid / i;
                if (tot >= totalTrips)
                    break;
            }
            if (tot >= totalTrips) {
                r = mid;
            } else
                l = mid + 1;
        }
        return r;
    }
};