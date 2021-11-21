class MyCircularDeque {
   public:
    /** Initialize your data structure here. Set the size of the deque to be k.
     */
    vector<int> v;
    int h, t, sz;
    MyCircularDeque(int k) {
        h = 0, t = 0, sz = 0;
        v.resize(k);
    }

    /** Adds an item at the front of Deque. Return true if the operation is
     * successful. */
    bool insertFront(int value) {
        if (sz == v.size())
            return false;
        h = (h + v.size() - 1) % v.size();
        v[h] = value;
        sz++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is
     * successful. */
    bool insertLast(int value) {
        if (sz == v.size())
            return false;
        v[t] = value;
        sz++;
        t = (t + 1) % v.size();
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is
     * successful. */
    bool deleteFront() {
        if (sz == 0)
            return false;
        h = (h + 1) % v.size();
        sz--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is
     * successful. */
    bool deleteLast() {
        if (sz == 0)
            return false;
        t = (t + v.size() - 1) % v.size();
        sz--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (sz == 0)
            return -1;
        return v[h];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (sz == 0)
            return -1;
        return v[(t + v.size() - 1) % v.size()];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() { return sz == 0; }

    /** Checks whether the circular deque is full or not. */
    bool isFull() { return sz == v.size(); }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */