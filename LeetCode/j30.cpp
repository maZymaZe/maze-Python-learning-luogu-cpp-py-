class MinStack {
   public:
    /** initialize your data structure here. */
    stack<int> a, b;
    int mi;
    MinStack() {}

    void push(int x) {
        if (a.empty())
            mi = x;
        else
            mi = std::min(b.top(), x);
        a.push(x);
        b.push(mi);
    }

    void pop() { a.pop(), b.pop(); }

    int top() { return a.top(); }

    int min() { return b.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */