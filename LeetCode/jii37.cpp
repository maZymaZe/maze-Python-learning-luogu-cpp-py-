class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> tr;
        int l = asteroids.size();
        vector<int> ans;
        for (int i = 0; i < l; i++) {
            if (tr.empty()) {
                if (asteroids[i] < 0) {
                    ans.push_back(asteroids[i]);
                } else {
                    tr.push_back(asteroids[i]);
                }
            } else {
                if (asteroids[i] > 0) {
                    tr.push_back(asteroids[i]);
                } else {
                    int ex = 1;
                    while (!tr.empty()) {
                        if (-asteroids[i] > tr.back()) {
                            tr.pop_back();
                        } else if (-asteroids[i] == tr.back()) {
                            tr.pop_back();
                            ex = 0;
                            break;
                        } else {
                            ex = 0;
                            break;
                        }
                    }
                    if (ex)
                        ans.push_back(asteroids[i]);
                }
            }
        }
        for (int i : tr) {
            ans.push_back(i);
        }
        return ans;
    }
};