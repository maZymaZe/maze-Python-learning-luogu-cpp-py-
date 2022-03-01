class StockSpanner {
   public:
    vector<int> x, y;
    int no;
    StockSpanner() { no = 0; }

    int next(int price) {
        no++;
        while (!x.empty()) {
            if (price >= x.back())
                x.pop_back(), y.pop_back();
            else
                break;
        }
        int ret;
        if (x.empty())
            ret = no;
        else
            ret = no - y.back();
        x.push_back(price), y.push_back(no);
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */