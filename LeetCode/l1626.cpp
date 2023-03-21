struct PR {
    int x, y;
    bool operator<(const PR& t) const {
        return (x == t.x) ? (y < t.y) : (x < t.x);
    }
};
class Solution {
   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int l = scores.size();
        vector<PR> v;
        for (int i = 0; i < l; i++)
            v.push_back({ages[i], scores[i]});
        sort(v.begin(), v.end());
        map<int, int> mp;
        mp[0] = 0;
        for (const PR& i : v) {
            auto it = mp.upper_bound(i.y);
            --it;
            auto nk = i.y, nv = it->second + i.y;
            ++it;
            if (it != mp.end() && it->second > nv && it->first <= nk)
                continue;
            auto jt = mp.upper_bound(nk);
            while (1) {
                if (jt == mp.end())
                    break;
                if (jt->second <= nv) {
                    jt = mp.erase(jt);
                } else
                    break;
            }
            mp[nk] = nv;
        }
        auto it = mp.end();
        --it;
        return it->second;
    }
};