class MovingAverage {
   public:
    /** Initialize your data structure here. */
    list<int> ls;
    int tot = 0;
    int lm;
    MovingAverage(int size) { lm = size; }

    double next(int val) {
        ls.push_back(val);
        tot += val;
        if (ls.size() > lm) {
            tot -= ls.front();
            ls.pop_front();
        }
        return 1.0 * tot / ls.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */