class StockPrice {
   public:
    int lst = -1;
    map<int, int> tp;
    map<int, int> pc;
    StockPrice() {}

    void update(int timestamp, int price) {
        if (timestamp > lst)
            lst = timestamp;
        if (tp.count(timestamp)) {
            int x = tp[timestamp];
            if (pc[x] == 1)
                pc.erase(x);
            else
                pc[x]--;
        }
        tp[timestamp] = price;
        pc[price]++;
    }

    int current() { return tp[lst]; }

    int maximum() {
        auto it = pc.end();
        --it;
        return it->first;
    }

    int minimum() { return pc.begin()->first; }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */