class Solution {
   public:
    bool circularArrayLoop(vector<int>& nums) {
        int l = nums.size(), p = 0;
        vector<int> vis(l);
        for (int i = 0; i < l; i++) {
            if (vis[i] == 0) {
                p++;
                if (nums[i] > 0) {
                    vis[i] = p;
                } else
                    vis[i] = -p;
                int nx = ((i + nums[i]) % l + l) % l;
                if (nx == i)
                    continue;
                while (1) {
                    if (vis[nx] == 0) {
                        if (nums[nx] * vis[i] > 0) {
                            vis[nx] = vis[i];
                            if (nx == ((nx + nums[nx]) % l + l) % l)
                                break;
                            nx = ((nx + nums[nx]) % l + l) % l;
                        } else {
                            break;
                        }
                    } else {
                        if (vis[nx] == vis[i])
                            return true;
                        else
                            break;
                    }
                }
            }
        }
        return false;
    }
};