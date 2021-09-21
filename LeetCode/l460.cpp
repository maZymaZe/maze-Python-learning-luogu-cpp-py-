struct NODE {
    int key, val, fre;
};
class LFUCache {
   public:
    int mf, sz;

    unordered_map<int, list<NODE>::iterator> kt;
    unordered_map<int, list<NODE>> ft;
    LFUCache(int capacity) {
        mf = 0, sz = capacity;
        kt.clear();
        ft.clear();
    }

    int get(int key) {
        if (sz == 0)
            return -1;
        auto it = kt.find(key);
        if (it == kt.end())
            return -1;
        auto node = it->second;
        int v = node->val, f = node->fre;
        ft[f].erase(node);
        if (ft[f].size() == 0) {
            ft.erase(f);
            if (mf == f)
                mf++;
        }
        ft[f + 1].push_front({key, v, f + 1});
        kt[key] = ft[f + 1].begin();
        return v;
    }

    void put(int key, int value) {
        if (sz == 0)
            return;
        auto it = kt.find(key);
        if (it == kt.end()) {
            if (kt.size() == sz) {
                auto it2 = ft[mf].back();
                kt.erase(it2.key);
                ft[mf].pop_back();
                if (ft[mf].size() == 0)
                    ft.erase(mf);
            }
            ft[1].push_front({key, value, 1});
            kt[key] = ft[1].begin();
            mf = 1;
        } else {
            auto node = it->second;
            int f = node->fre;
            ft[f].erase(node);
            if (ft[f].size() == 0) {
                ft.erase(f);
                if (mf == f)
                    mf++;
            }
            ft[f + 1].push_front({key, value, f + 1});
            kt[key] = ft[f + 1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */