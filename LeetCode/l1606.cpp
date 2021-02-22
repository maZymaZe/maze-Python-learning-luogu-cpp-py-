struct pr {
    int id, release;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) { return a.release > b.release; }
};
class Solution {
   public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> avs;
        for (int i = 0; i < k; i++)
            avs.insert(i);
        int l = arrival.size();
        vector<int> cnt(k);
        priority_queue<pr, vector<pr>, cmp> q;
        for (int i = 0; i < l; i++) {
            while (!q.empty() && q.top().release <= arrival[i]) {
                avs.insert(q.top().id);
                q.pop();
            }
            if (avs.empty())
                continue;
            else {
                auto t = avs.lower_bound(i % k);
                if (t == avs.end())
                    t = avs.lower_bound(0);
                cnt[*t]++;
                q.push({*t, arrival[i] + load[i]});
                avs.erase(*t);
            }
        }
        int mxl=cnt[0];
        for(int i=1;i<k; i++)if(cnt[i]>mxl)mxl=cnt[i];
        vector<int> ans;
        for(int i=0;i<k; i++)if(cnt[i]==mxl)ans.push_back(i);
        return ans;

    }
};