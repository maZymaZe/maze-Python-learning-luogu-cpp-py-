struct NODE {
    int val;
    unordered_set<string> keys;
    NODE(int x) { val = x; }
};
class AllOne {
   public:
    /** Initialize your data structure here. */
    unordered_map<string, list<NODE>::iterator> k2i;
    list<NODE> ls;
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key
     * by 1. */
    void inc(string key) {
        list<NODE>::iterator nn;
        if (k2i.count(key)) {
            list<NODE>::iterator cn = k2i[key];
            nn = next(cn, 1);
            if (nn == ls.end() || nn->val > cn->val + 1) {
                nn = ls.insert(nn, NODE(cn->val + 1));
            }
            cn->keys.erase(key);
            if (cn->keys.empty())
                ls.erase(cn);
        } else {
            nn = ls.begin();
            if (ls.empty() || nn->val != 1) {
                nn = ls.insert(ls.begin(), NODE(1));
            }
        }
        nn->keys.insert(key);
        k2i[key] = nn;
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the
     * data structure. */
    void dec(string key) {
        if (k2i.count(key)) {
            list<NODE>::iterator cn = k2i[key];
            if (cn->val > 1) {
                list<NODE>::iterator ln = next(cn, -1);
                if (cn == ls.begin() || ln->val < cn->val - 1) {
                    ln = ls.insert(cn, NODE(cn->val - 1));
                }
                ln->keys.insert(key);
                k2i[key] = ln;
            } else
                k2i.erase(key);
            cn->keys.erase(key);
            if (cn->keys.empty()) {
                ls.erase(cn);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return ls.empty() ? "" : (*ls.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() { return ls.empty() ? "" : (*ls.begin()->keys.begin()); }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */