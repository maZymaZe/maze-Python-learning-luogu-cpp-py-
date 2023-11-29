class SmallestInfiniteSet {
   public:
    int vis[1001] = {0};
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for (int i = 1; i < 1001; i++)
            pq.push(i);
    }

    int popSmallest() {
        int t = pq.top();
        vis[t] = 1;
        pq.pop();
        return t;
    }

    void addBack(int num) {
        if (vis[num])
            vis[num] = 0, pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */