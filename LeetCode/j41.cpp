class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> xgd;
    priority_queue<int> dgd;
    MedianFinder() {}

    void addNum(int num) {
        xgd.push(num);
        if (dgd.size() && xgd.top() < dgd.top()) {
            int a = xgd.top(), b = dgd.top();
            xgd.pop();
            dgd.pop();
            dgd.push(a), xgd.push(b);
        }
        if (xgd.size() > dgd.size() + 1) {
            int a = xgd.top();
            xgd.pop();
            dgd.push(a);
        }
    }

    double findMedian() {
        if (xgd.size() > dgd.size())
            return xgd.top();
        return 1.0 * (xgd.top() + dgd.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */