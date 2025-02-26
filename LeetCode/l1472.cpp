class BrowserHistory {
   public:
    vector<string> v;
    int cur = 0;
    BrowserHistory(string homepage) { v.push_back(homepage); }

    void visit(string url) {
        v.resize(cur + 1);
        cur++;
        v.push_back(url);
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return v[cur];
    }

    string forward(int steps) {
        cur = min(cur + steps, (int)(v.size() - 1));
        return v[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */