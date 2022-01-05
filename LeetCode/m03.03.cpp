class StackOfPlates {
   public:
    vector<stack<int>> s;
    int c;
    StackOfPlates(int cap) { c = cap; }

    void push(int val) {
        if (c == 0)
            return;
        if (s.empty() || s.back().size() == c) {
            s.push_back(stack<int>());
        }
        s.back().push(val);
    }

    int pop() {
        if (c == 0 || s.empty())
            return -1;
        int ret = s.back().top();
        s.back().pop();
        if (s.back().empty())
            s.pop_back();
        return ret;
    }

    int popAt(int index) {
        if (c == 0 || index >= s.size() || s[index].empty())
            return -1;
        int ret = s[index].top();
        s[index].pop();
        if (s[index].empty())
            s.erase(s.begin() + index);
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */