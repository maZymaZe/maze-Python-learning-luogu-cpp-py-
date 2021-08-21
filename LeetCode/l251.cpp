class Vector2D {
   public:
    vector<int>::iterator it2;
    vector<vector<int>>::iterator it1, ee;
    int hn;
    Vector2D(vector<vector<int>>& vec) {
        it1 = vec.begin();
        ee = vec.end();
        while (it1 != ee && it1->size() == 0)
            ++it1;
        hn = 1;
        if (it1 != vec.end()) {
            it2 = it1->begin();
            if (it2 == it1->end()) {
                hn = 0;
            }
        } else
            hn = 0;
    }

    int next() {
        auto it3 = it2;
        ++it2;
        if (it2 == it1->end()) {
            ++it1;
            while (it1 != ee && it1->size() == 0)
                ++it1;
            if (it1 == ee) {
                hn = 0;
            } else {
                it2 = it1->begin();
            }
        }
        return *it3;
    }

    bool hasNext() { return hn; }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */