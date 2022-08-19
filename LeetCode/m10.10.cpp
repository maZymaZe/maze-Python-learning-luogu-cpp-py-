class StreamRank {
   public:
    int TA[200000] = {0};
    StreamRank() {}

    void track(int x) {
        x++;
        while (x < 200000) {
            TA[x]++;
            x += (-x & x);
        }
    }

    int getRankOfNumber(int x) {
        x++;
        int ret = 0;
        while (x) {
            ret += TA[x];
            x -= (-x & x);
        }
        return ret;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */