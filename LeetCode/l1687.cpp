class Solution {
   public:
    int boxDelivering(vector<vector<int>>& boxes,
                      int portsCount,
                      int maxBoxes,
                      int maxWeight) {
        int l = boxes.size();
        vector<long long> dp(l + 1), wps(l + 1), dps(l + 1);
        for (int i = 0; i < l; i++) {
            wps[i + 1] = wps[i] + boxes[i][1];
            if (i)
                dps[i + 1] = dps[i] + (boxes[i][0] != boxes[i - 1][0]);
        }
        deque<long long> dq, p;
        dq.push_back(0), p.push_back(0);
        dp[0] = 0;
        for (int i = 1; i <= l; i++) {
            while (!p.empty()) {
                int j = p.front();
                if (wps[i] - wps[j] > maxWeight || i - j > maxBoxes) {
                    p.pop_front();
                    dq.pop_front();
                } else
                    break;
            }
            dp[i] = (dp.empty() ? 0 : (dq.front())) + dps[i] + 2;
            if (i != l) {
                long long nx = dp[i] - dps[i + 1];
                while (!dq.empty() && dq.back() >= nx) {
                    dq.pop_back();
                    p.pop_back();
                }
                dq.push_back(nx);
                p.push_back(i);
            }
        }
        return dp[l];
    }
};