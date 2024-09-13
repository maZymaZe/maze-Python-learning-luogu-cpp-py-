struct PR {
    int ct, id;
    bool operator<(const PR& other) const { return ct < other.ct; }
};
class Solution {
   public:
    int maximumRobots(vector<int>& chargeTimes,
                      vector<int>& runningCosts,
                      long long budget) {
        int ans = 0;
        int n = chargeTimes.size(), l = 0, r = 0;
        long long sum = 0, used;
        priority_queue<PR> pq;
        while (l < n) {
            sum += runningCosts[l];
            pq.push({chargeTimes[l], l});
            do {
                used = sum * (l - r + 1) + pq.top().ct;
                if (used <= budget) {
                    break;
                } else {
                    sum -= runningCosts[r];
                    r++;
                    while (!pq.empty() && r > pq.top().id) {
                        pq.pop();
                    }
                }
            } while (!pq.empty());
            ans = max(ans, l - r + 1);
            l++;
        }
        return ans;
    }
};