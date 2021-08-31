class Solution {
   public:
    bool canJump(vector<int>& nums) {
        queue<int> q;
        int l = nums.size();
        if (l == 1)
            return true;
        vector<int> vis(l);
        q.push(0);
        vis[0] = 1;
        while (!q.empty()) {
            int tt = q.front();
            q.pop();
            if (tt >= l || tt < 0)
                continue;

            for (int i = min(l - 1, tt + nums[tt]); !vis[i]; --i) {
                if (i == l - 1)
                    return true;
                vis[i] = 1;
                q.push(i);
            }
        }
        return false;
    }
};