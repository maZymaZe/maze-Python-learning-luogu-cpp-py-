class SortedStack {
   public:
    stack<int> a, b;
    SortedStack() {}

    void push(int val) {
        while (!(a.empty() || a.top() >= val)) {
            b.push(a.top()), a.pop();
        }
        a.push(val);
        while (!b.empty())
            a.push(b.top()), b.pop();
    }

    void pop() {
        if (!a.empty())
            a.pop();
    }

    int peek() {
        if (!a.empty())
            return a.top();
        return -1;
    }

    bool isEmpty() { return a.empty(); }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */