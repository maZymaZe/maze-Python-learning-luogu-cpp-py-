class Solution {
   public:
    int maxTaskAssign(vector<int>& tasks,
                      vector<int>& workers,
                      int pills,
                      int strength) {
        sort(tasks.begin(), tasks.end());
        int n = tasks.size(), m = workers.size();
        int l = 0, r = min(n, m);
        multiset<int> st;
        for (int i : workers) {
            st.insert(i);
        }
        while (l < r) {
            int mid = (l + r + 1) / 2;
            int pc = 0;
            int ok = 1;
            auto s = st;
            for (int i = mid - 1; i >= 0; i--) {
                if (s.empty()) {
                    ok = 0;
                    break;
                }
                auto it = s.lower_bound(tasks[i]);
                if (it == s.end()) {
                    it = s.lower_bound(tasks[i] - strength);
                    if (it == s.end()) {
                        ok = 0;
                        break;
                    } else {
                        s.erase(it);
                        pc++;
                    }
                } else {
                    s.erase(it);
                }
            }
            if (ok && pc <= pills)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};