struct PR {
    int v, pos;
    bool operator<(const PR& x) const {
        if (v == x.v)
            return pos > x.pos;
        return v > x.v;
    }
};
class Solution {
   public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1)
            return nums;
        int l = nums.size(), mx = 0;
        priority_queue<PR> pq;
        for (int i = 0; i < l; i++) {
            mx = max(mx, nums[i]);
            pq.push({nums[i], i});
        }
        while (k > 0) {
            PR p = pq.top();
            if ((long long)p.v * multiplier > mx)
                break;
            pq.pop();
            p.v *= multiplier;
            pq.push(p);
            k--;
        }
        vector<int> ans(l);
        int qpc = k / l, MOD = 1e9 + 7;
        k %= l;
        for (int i = 0; i < l; i++) {
            PR p = pq.top();
            if (i + 1 <= k) {
                p.v = (long long)p.v * multiplier % MOD;
            }
            ans[p.pos] = p.v;
            pq.pop();
        }
        long long tmp = 1;
        while (qpc) {
            if (qpc % 2)
                tmp = tmp * multiplier % MOD;
            qpc /= 2;
            multiplier = (long long)multiplier * multiplier % MOD;
        }
        for (int i = 0; i < l; i++) {
            ans[i] = (long long)ans[i] * tmp % MOD;
        }
        return ans;
    }
};