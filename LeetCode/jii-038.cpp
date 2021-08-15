class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int l = temperatures.size();

        vector<int> ans(l);
        deque<int> st, pos;
        for (int i = l - 1; i >= 0; i--) {
            if (st.empty()) {
                ans[i] = 0;
                st.push_back(temperatures[i]);
                pos.push_back(i);
            } else {
                int idx = upper_bound(st.begin(), st.end(), temperatures[i]) -
                          st.begin();
                if (idx == st.size()) {
                    ans[i] = 0;
                } else
                    ans[i] = pos[idx] - i;
                while (!st.empty() && temperatures[i] >= st.front()) {
                    st.pop_front();
                    pos.pop_front();
                }
                st.push_front(temperatures[i]);
                pos.push_front(i);
            }
        }
        return ans;
    }
};