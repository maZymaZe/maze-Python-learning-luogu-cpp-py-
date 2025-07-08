class Solution {
   public:
    int maxFreeTime(int eventTime,
                    int k,
                    vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> st;
        int l = startTime.size();
        st.push_back(startTime[0]);
        for (int i = 1; i < l; i++) {
            st.push_back(startTime[i] - endTime[i - 1]);
        }
        st.push_back(eventTime - endTime[l - 1]);
        int tl = st.size(), cur = 0;
        for (int i = 0; i <= k; i++) {
            cur += st[i];
        }
        int ans = cur;
        for (int i = 0; i + k + 1 < tl; i++) {
            cur -= st[i];
            cur += st[i + k + 1];
            ans = max(ans, cur);
        }
        return ans;
    }
};