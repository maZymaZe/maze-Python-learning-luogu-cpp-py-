class Solution {
   public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        map<int, int> mp;
        for (auto i : people)
            mp[i]++;
        while (!mp.empty()) {
            ans++;
            auto it = mp.end();
            it--;
            int r = limit - it->first;
            it->second--;
            if (it->second == 0)
                mp.erase(it);
            auto iit = mp.upper_bound(r);
            if (iit != mp.begin()) {
                --iit;
                iit->second--;
                if (iit->second == 0)
                    mp.erase(iit);
            }
        }
        return ans;
    }
};