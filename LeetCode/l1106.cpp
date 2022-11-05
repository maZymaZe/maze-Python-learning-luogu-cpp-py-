class Solution {
   public:
    string s;
    vector<int> nx;
    stack<int> sk;
    bool exp(int l, int r) {
        if (l + 1 == r) {
            if (s[l] == 't')
                return true;
            else
                return false;
        }
        if (s[l] == '!') {
            return !exp(l + 2, nx[l + 1]);
        }
        if (s[l] == '|') {
            int p = l + 2;
            for (int i = l + 2; i < r; i++) {
                if (nx[i])
                    i = nx[i];
                if (s[i] == ',') {
                    if (exp(p, i))
                        return true;
                    p = i + 1;
                }
            }
            if (exp(p, r - 1))
                return true;
            else
                return false;
        }
        if (s[l] == '&') {
            int p = l + 2;
            for (int i = l + 2; i < r; i++) {
                if (nx[i])
                    i = nx[i];
                if (s[i] == ',') {
                    if (!exp(p, i))
                        return false;
                    p = i + 1;
                }
            }
            if (!exp(p, r - 1))
                return false;
            else
                return true;
        }
        assert(0);
        return 0;
    }
    bool parseBoolExpr(string expression) {
        s = expression;
        nx.resize(expression.size());
        int l = nx.size();
        for (int i = 0; i < l; i++) {
            if (expression[i] == '(') {
                sk.push(i);
            }
            if (expression[i] == ')') {
                nx[sk.top()] = i;
                sk.pop();
            }
        }
        return exp(0, s.size());
    }
};