class CountIntervals {
   public:
    map<int, int> mp;
    int ans = 0;
    CountIntervals() {}

    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        int nl = left, nr = right, ta = right - left + 1;
        if (it != mp.begin()) {
            --it;
            if (it->second >= left) {
                nl = it->first;
                nr = max(nr, it->second);
                ta -= min(right, it->second) - left + 1;
                it = mp.erase(it);
            } else
                ++it;
        }
        while (it != mp.end() && it->first <= right) {
            nr = max(nr, it->second);
            ta -= min(right, it->second) - it->first + 1;
            it = mp.erase(it);
        }
        mp[nl] = nr;
        ans += ta;
    }

    int count() { return ans; }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */