struct PR {
    int x, p;
    bool operator<(const PR& o) const {
        if (o.x == x)
            return p > o.p;
        return x > o.x;
    }
};
class Solution {
   public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<PR> pq;
        int l = nums.size(), p = -1;
        for (int i = 0; i < l - k; i++) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++) {
            pq.push({nums[l - k + i], l - k + i});
            PR t = pq.top();
            while (t.p < p) {
                pq.pop();
                t = pq.top();
            }
            p = t.p;
            ans.push_back(t.x);
            pq.pop();
        }
        return ans;
    }
};
