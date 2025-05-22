class Solution {
   public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> pq;
        int n = nums.size(), cur = 0, u = 0;
        vector<vector<int>> qs(n);
        for (vector<int>& q : queries) {
            qs[q[0]].push_back(q[1]);
        }
        vector<int> minu(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j : qs[i]) {
                pq.push(j);
            }
            cur -= minu[i];
            while (!pq.empty() && cur < nums[i]) {
                if (pq.top() < i) {
                    pq.pop();
                    continue;
                }
                cur++;
                minu[pq.top() + 1]++;
                pq.pop();
                u++;
            }
            if (cur < nums[i]) {
                return -1;
            }
        }
        return queries.size() - u;
    }
};