class MyCircularQueue {
   public:
    int a[1100] = {0}, l = 0, r = 0, lim = 0, sz = 0;
    /** Initialize your data structure here. Set the size of the queue to be k.
     */
    MyCircularQueue(int k) { lim = k; }

    /** Insert an element into the circular queue. Return true if the operation
     * is successful. */
    bool enQueue(int value) {
        if (sz >= lim)
            return false;
        a[r] = value;
        r++;
        r %= lim;
        sz++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation
     * is successful. */
    bool deQueue() {
        if (sz == 0)
            return false;
        l += 1;
        l %= lim;
        sz--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (sz == 0)
            return -1;
        return a[l];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (sz == 0)
            return -1;
        int t = (r + lim - 1) % lim;
        return a[t];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() { return sz == 0; }

    /** Checks whether the circular queue is full or not. */
    bool isFull() { return sz == lim; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */