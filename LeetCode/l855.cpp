class ExamRoom {
   public:
    set<int> s;
    int N;
    ExamRoom(int n) { N = n; }

    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        }
        auto pre = s.begin(), ls = s.begin();
        ++ls;
        int maxdis = *pre, ans = 0;
        while (ls != s.end()) {
            int tx = (*ls - *pre) / 2;
            int tp = *pre + tx;
            if (tx > maxdis) {
                maxdis = tx, ans = tp;
            }
            ++ls;
            ++pre;
        }
        int tx = (N - *pre - 1);
        if (tx > maxdis) {
            maxdis = tx, ans = N - 1;
        }
        s.insert(ans);
        return ans;
    }

    void leave(int p) { s.erase(p); }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */