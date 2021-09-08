struct pr {
    int l, r;
    bool operator<(const pr& x) const { return l < x.l; }
};
class SummaryRanges {
   public:
    /** Initialize your data structure here. */
    set<pr> st;
    SummaryRanges() { st.clear(); }

    void addNum(int val) {
        auto it = st.upper_bound({val, 0});
        int nxl = val, nxr = val;
        if (it != st.end()) {
            if (it->l == val + 1) {
                nxr = it->r;
                it = st.erase(it);
            }
        }
        if (it != st.begin()) {
            --it;
            if (it->l == val || it->r >= val)
                return;
            if (it->r == val - 1) {
                nxl = it->l;
                it = st.erase(it);
            }
        }
        st.insert({nxl, nxr});
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto c : st) {
            ans.push_back({c.l, c.r});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */