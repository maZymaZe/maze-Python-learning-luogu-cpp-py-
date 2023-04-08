
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                       vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        int id = 0;
        for (auto& s : req_skills) {
            mp.insert({s, id++});
        }
        vector<int> pp;
        for (auto& v : people) {
            int sk = 0;
            for (auto& s : v) {
                sk |= (1 << mp[s]);
            }
            pp.push_back(sk);
        }
        int sz = (1 << id), l = pp.size();
        vector<vector<int>> dp(l + 1, vector<int>(sz, 0x3f3f3f3f));
        auto pre = dp;
        dp[0][0] = 0;
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j < sz; j++) {
                if (dp[i][j] > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                    pre[i][j] = j;
                }
                int nx = (j | pp[i - 1]);
                if (dp[i][nx] > dp[i - 1][j] + 1) {
                    dp[i][nx] = dp[i - 1][j] + 1;
                    pre[i][nx] = j;
                }
            }
        }
        int tg = sz - 1;
        vector<int> ans;
        for (int i = l; i > 0; i--) {
            if (pre[i][tg] <= tg && dp[i][tg] == dp[i - 1][pre[i][tg]] + 1) {
                tg = pre[i][tg];
                ans.push_back(i - 1);
            }
        }
        return ans;
    }
};
int main() {
    vector<string> a{"a", "b", "c"}, b{"a"}, c{"b"}, d{"b", "c"};
    vector<vector<string>> e{b, c, d};
    Solution().smallestSufficientTeam(a, e);
}