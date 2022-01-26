class DetectSquares {
   public:
    map<pair<int, int>, int> mp;
    DetectSquares() {}

    void add(vector<int> point) { mp[{point[0], point[1]}]++; }

    int count(vector<int> point) {
        int l = mp.size(), c = 0;
        for (auto& it : mp) {
            if (it.first.first != point[0] && it.first.second != point[1] &&
                abs(it.first.first - point[0]) ==
                    abs(it.first.second - point[1])) {
                if (mp.count({it.first.first, point[1]}) &&
                    mp.count({point[0], it.first.second}))
                    c += it.second * mp[{point[0], it.first.second}] *
                         mp[{it.first.first, point[1]}];
            }
        }
        return c;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */