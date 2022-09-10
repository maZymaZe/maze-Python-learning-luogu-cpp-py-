struct LN {
    int key, val;
    LN* pre;
    LN* nex;
    LN() : key(0), val(0), pre(nullptr), nex(nullptr) {}
    LN(int _key, int _value)
        : key(_key), val(_value), pre(nullptr), nex(nullptr) {}
};
class LRUCache {
   private:
    unordered_map<int, LN*> cache;
    LN* head;
    LN* tail;
    int size, capacity;

   public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new LN();
        tail = new LN();
        head->nex = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key))
            return -1;
        LN* node = cache[key];
        mv(node);
        return node->val;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            LN* x = new LN(key, value);
            cache[key] = x;
            x->pre = head;
            x->nex = head->nex;
            head->nex->pre = x;
            head->nex = x;
            ++size;
            if (size > capacity) {
                LN* removed = rmt();

                cache.erase(removed->key);
                --size;
            }
        } else {
            LN* node = cache[key];
            node->val = value;
            mv(node);
        }
    }
    void mv(LN* x) {
        x->pre->nex = x->nex;
        x->nex->pre = x->pre;

        x->pre = head;
        x->nex = head->nex;
        head->nex->pre = x;
        head->nex = x;
    }
    LN* rmt() {
        LN* x = tail->pre;
        x->pre->nex = x->nex;
        x->nex->pre = x->pre;
        return x;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */