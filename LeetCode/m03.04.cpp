class MyQueue {
   public:
    /** Initialize your data structure here. */
    stack<int> a, b;
    MyQueue() {
        while (!a.empty())
            a.pop();
        while (!b.empty())
            b.pop();
    }

    /** Push element x to the back of queue. */
    void push(int x) { a.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (b.empty()) {
            while (!a.empty()) {
                int t = a.top();
                b.push(t);
                a.pop();
            }
        }
        if (!b.empty()) {
            int t = b.top();
            b.pop();
            return t;
        }
        return -1;
    }

    /** Get the front element. */
    int peek() {
        if (b.empty()) {
            while (!a.empty()) {
                int t = a.top();
                b.push(t);
                a.pop();
            }
        }
        if (!b.empty()) {
            return b.top();
        }
        return -1;
    }

    /** Returns whether the queue is empty. */
    bool empty() { return a.empty() && b.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */