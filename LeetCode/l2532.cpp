struct PR {
    int op, id;
};
class Solution {
   public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        for (int i = 0; i < k; i++) {
            time[i].push_back(i);
        }
        sort(time.begin(), time.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 int ax = a[0] + a[2], bx = b[0] + b[2];
                 if (ax == bx) {
                     return a[4] < b[4];
                 }
                 return ax < bx;
             });
        int onbridge = -1, box = 0, offbridgetime = -1, tg = -1, ans = 0;
        priority_queue<int> pq[2];
        for (int i = 0; i < k; i++) {
            pq[0].push(i);
        }
        map<int, vector<PR>> mp;
        mp[0] = vector<PR>();
        while (!mp.empty()) {
            auto& v = (mp.begin())->second;
            int now = mp.begin()->first;
            for (const auto& it : v) {
                pq[it.op].push(it.id);
            }
            if (onbridge != -1 && offbridgetime == now) {
                if (tg == 1) {
                    box++;
                    mp[now + time[onbridge][1]].push_back({1, onbridge});
                    onbridge = -1, tg = -1, offbridgetime = 0;
                } else {
                    ans = now;
                    if (box < n) {
                        mp[now + time[onbridge][3]].push_back({0, onbridge});
                    }
                    onbridge = -1, tg = -1, offbridgetime = 0;
                }
            }
            if (onbridge == -1) {
                if (!pq[1].empty()) {
                    onbridge = pq[1].top();
                    pq[1].pop();
                    offbridgetime = now + time[onbridge][2];
                    tg = 0;
                } else if (box < n && !pq[0].empty()) {
                    onbridge = pq[0].top();
                    pq[0].pop();
                    offbridgetime = now + time[onbridge][0];
                    tg = 1;
                }
                if (offbridgetime && !mp.count(offbridgetime))
                    mp[offbridgetime] = vector<PR>();
            }
            mp.erase(mp.begin());
        }
        return ans;
    }
};