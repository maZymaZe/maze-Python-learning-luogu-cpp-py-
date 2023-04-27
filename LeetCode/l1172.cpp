class DinnerPlates {
   public:
    int c, platecnt;
    map<int, int> u;
    vector<stack<int>> s;
    set<int> ful, e;
    DinnerPlates(int capacity) {
        c = capacity;
        platecnt = 0;
    }

    void push(int val) {
        if (ful.size() == platecnt && e.empty()) {
            s.push_back(stack<int>());
            e.insert(platecnt);
            platecnt++;
        }
        int id1 = -1, id2 = -1, op = 0;
        if (!u.empty()) {
            auto it = u.begin();
            id1 = it->first;
        }
        if (!e.empty()) {
            auto it = e.begin();
            id2 = *it;
        }
        if (id1 == -1)
            op = 2;
        else if (id2 == -1)
            op = 1;
        else if (id1 < id2)
            op = 1;
        else
            op = 2;
        if (op == 1) {
            s[id1].push(val);
            u[id1]++;
            if (u[id1] == c) {
                u.erase(id1);
                ful.insert(id1);
            }
        } else {
            s[id2].push(val);
            e.erase(id2);
            u[id2] = 1;
            if (u[id2] == c) {
                u.erase(id2);
                ful.insert(id2);
            }
        }
    }

    int pop() {
        int id1 = -1, id2 = -1, op = 0, ans;

        if (!u.empty()) {
            auto it = u.end();
            --it;
            id1 = it->first;
        }
        if (!ful.empty()) {
            auto it = ful.end();
            --it;
            id2 = *it;
        }
        if (id1 == -1 && id2 == -1) {
            return -1;
        }
        if (id1 == -1)
            op = 2;
        else if (id2 == -1)
            op = 1;
        else if (id1 > id2)
            op = 1;
        else
            op = 2;
        if (op == 1) {
            ans = s[id1].top();
            s[id1].pop();
            if (u[id1] == 1) {
                e.insert(id1);
                u.erase(id1);
            }
        } else {
            ans = s[id2].top();
            s[id2].pop();
            ful.erase(id2);
            u[id2] = c - 1;
            if (u[id2] == 0) {
                e.insert(id2);
                u.erase(id2);
            }
        }
        return ans;
    }

    int popAtStack(int index) {
        int ans;
        if (e.count(index)) {
            return -1;
        } else if (u.count(index)) {
            ans = s[index].top();
            s[index].pop();
            u[index]--;
            if (u[index] == 0) {
                u.erase(index);
                e.insert(index);
            }
            return ans;
        } else if (ful.count(index)) {
            ans = s[index].top();
            s[index].pop();
            u[index] = c - 1;
            ful.erase(index);
            if (u[index] == 0) {
                u.erase(index);
                e.insert(index);
            }
            return ans;
        }
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */