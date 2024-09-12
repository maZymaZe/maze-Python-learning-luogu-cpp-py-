class Solution {
   public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        map<int, int> mp;
        queue<int> q;
        int ans = 0;
        for (int i : nums)
            mp[i]++;
        while (!mp.empty()) {
            auto it = mp.end();
            --it;
            auto jt = mp.lower_bound(it->first / 2 + 1);
            if (jt == mp.begin()) {
                if (!q.empty()) {
                    if (it->first >= q.front())
                        break;
                    if (it->second == 1)
                        mp.erase(it);
                    else
                        it->second--;
                    mp[q.front()]++;
                    continue;
                } else
                    break;
            }
            --jt;
            // assert(2 * jt->first <= it->first);
            int i = it->first, j = jt->first;
            if (jt->second == 1) {
                mp.erase(j);
            } else
                mp[j]--;
            if (it->second == 1) {
                mp.erase(i);
            } else
                mp[i]--;
            ans += 2;
            q.push(j);
        }
        return ans;
    }
};