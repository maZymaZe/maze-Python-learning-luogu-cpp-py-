class MovingAverage {
   public:
    /** Initialize your data structure here. */
    list<int> ls;
    long long tot, sz;
    MovingAverage(int size) {
        ls.clear();
        tot = 0;
        sz = size;
    }

    double next(int val) {
        ls.push_back(val);
        tot += val;
        if (ls.size() > sz)
            tot -= ls.front(), ls.pop_front();
        return (double)tot / ls.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */