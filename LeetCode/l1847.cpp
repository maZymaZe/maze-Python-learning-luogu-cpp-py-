class Solution {
   public:
    vector<int> closestRoom(vector<vector<int>>& rooms,
                            vector<vector<int>>& queries) {
        int rs = rooms.size(), qs = queries.size();
        for (int i = 0; i < qs; i++)
            queries[i].push_back(i);
        sort(rooms.begin(), rooms.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        sort(queries.begin(), queries.end(),
             [&](const vector<int>& a, const vector<int>& b) {
                 return a[1] > b[1];
             });
        vector<int> ans(qs);
        map<int, int> mp;
        int p = 0;
        for (int i = 0; i < qs; i++) {
            while (p < rs && rooms[p][1] >= queries[i][1]) {
                mp.insert({rooms[p][0], rooms[p][1]});
                p++;
            }
            int ta = -1, dis = 0x3f3f3f3f;
            if (!mp.empty()) {
                auto it = mp.lower_bound(queries[i][0]);
                if (it != mp.end()) {
                    ta = it->first;
                    dis = it->first - queries[i][0];
                }
                if (it != mp.begin()) {
                    --it;
                    if (queries[i][0] - it->first <= dis) {
                        ta = it->first;
                    }
                }
            }
            ans[queries[i][2]] = ta;
        }
        return ans;
    }
};