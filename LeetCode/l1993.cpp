class LockingTree {
   public:
    vector<int> ls, pr;
    vector<vector<int>> ss;
    int n;
    LockingTree(vector<int>& parent) {
        n = parent.size();
        ls.resize(n);
        pr = parent;
        ss.resize(n);
        for (int i = 1; i < n; i++) {
            ss[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (ls[num] == 0) {
            ls[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (ls[num] == user) {
            ls[num] = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (ls[num] != 0) {
            return false;
        }
        int t = num;
        while (t != -1) {
            if (ls[t])
                return false;
            t = pr[t];
        }
        vector<int> s;
        queue<int> q;
        for (int i : ss[num])
            q.push(i);
        int f = 0;
        while (!q.empty()) {
            s.push_back(q.front());
            if (ls[q.front()] != 0) {
                f = 1;
                ls[q.front()] = 0;
            }
            for (int i : ss[q.front()])
                q.push(i);
            q.pop();
        }
        if (f) {
            ls[num] = user;
            return true;
        }
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */