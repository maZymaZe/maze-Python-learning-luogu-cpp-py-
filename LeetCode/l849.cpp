class Solution {
   public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0, l = seats.size(), pre = -1;
        for (int i = 0; i < l; i++) {
            if (seats[i]) {
                if (pre == -1) {
                    ans = max(ans, i);
                } else {
                    ans = max(ans, (i - pre) / 2);
                }
                pre = i;
            }
        }
        ans = max(ans, l - pre - 1);
        return ans;
    }
};