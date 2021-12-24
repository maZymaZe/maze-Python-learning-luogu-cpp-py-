class Solution {
   public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int, int> mp;
        int now = 0, l = days.size(), ans = 0;
        while (now < l || !mp.empty()) {
            if (now < l && apples[now]) {
                mp[now + days[now]] += apples[now];
            }
            while (!mp.empty()) {
                auto it = mp.begin();
                if (it->first <= now) {
                    mp.erase(it);
                } else
                    break;
            }
            if (!mp.empty()) {
                auto it = mp.begin();
                ans++;
                it->second--;
                if (it->second == 0)
                    mp.erase(it);
            }
            now++;
        }
        return ans;
    }
};