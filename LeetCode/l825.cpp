class Solution {
   public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int l = ages.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            int x = ages[i];

            int lb = (0.5 * x + 7);
            int ub = x;
            if (x < 100)
                ub = min(ub, 100);
            if (lb >= ub)
                continue;
            if (x > lb && x <= ub)
                ans--;
            ans += upper_bound(ages.begin(), ages.end(), ub) -
                   upper_bound(ages.begin(), ages.end(), lb);
        }
        return ans;
    }
};