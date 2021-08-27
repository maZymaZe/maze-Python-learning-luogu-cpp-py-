class Solution {
   public:
    string exp;
    vector<string> ans;
    int l, el, tg, op[4] = {'+', '-', '*', '$'};
    stack<long long> st;
    stack<int> oo;
    long long cal() {
        for (int i = 0; i < el; i++) {
            if (exp[i] >= '0' && exp[i] <= '9')
                st.push(exp[i] - '0');
            else if (exp[i] == '+' || exp[i] == '-') {
                while (!oo.empty()) {
                    int tt = oo.top();
                    oo.pop();
                    long long a, b;
                    b = st.top(), st.pop(), a = st.top(), st.pop();
                    if (tt == '+')
                        st.push(a + b);
                    if (tt == '-')
                        st.push(a - b);
                    if (tt == '*')
                        st.push(a * b);
                    if (tt == '$') {
                        int ll = 0;
                        long long s = b;
                        while (s)
                            s /= 10, ll++;
                        if (!ll)
                            ll++;
                        while (ll) {
                            a *= 10;
                            ll--;
                        }
                        st.push(a + b);
                    }
                }
                oo.push(exp[i]);
            } else if (exp[i] == '*') {
                while (!oo.empty() && (oo.top() == '*' || oo.top() == '$')) {
                    int tt = oo.top();
                    oo.pop();
                    long long a, b;
                    b = st.top(), st.pop(), a = st.top(), st.pop();

                    if (tt == '*')
                        st.push(a * b);
                    if (tt == '$') {
                        int ll = 0;
                        long long s = b;
                        while (s)
                            s /= 10, ll++;
                        if (!ll)
                            ll++;
                        while (ll) {
                            a *= 10;
                            ll--;
                        }
                        st.push(a + b);
                    }
                }
                oo.push(exp[i]);
            } else if (exp[i] == '$') {
                while (!oo.empty() && (oo.top() == '$')) {
                    int tt = oo.top();
                    oo.pop();
                    long long a, b;
                    b = st.top(), st.pop(), a = st.top(), st.pop();

                    if (tt == '$') {
                        int ll = 0;
                        long long s = b;
                        while (s)
                            s /= 10, ll++;
                        if (!ll)
                            ll++;
                        while (ll) {
                            a *= 10;
                            ll--;
                        }
                        st.push(a + b);
                    }
                }
                oo.push(exp[i]);
            }
        }
        while (!oo.empty()) {
            int tt = oo.top();
            oo.pop();
            long long a, b;
            b = st.top(), st.pop(), a = st.top(), st.pop();
            if (tt == '+')
                st.push(a + b);
            if (tt == '-')
                st.push(a - b);
            if (tt == '*')
                st.push(a * b);
            if (tt == '$') {
                int ll = 0;
                long long s = b;
                while (s)
                    s /= 10, ll++;
                if (!ll)
                    ll++;
                while (ll) {
                    a *= 10;
                    ll--;
                }
                st.push(a + b);
            }
        }
        long long ret = st.top();
        while (!st.empty())
            st.pop();
        while (!oo.empty())
            oo.pop();
        return ret;
    }
    void dfs(int pos) {
        if (pos == el) {
            for (int i = 0; i < el - 1; i++) {
                if (exp[i] == '0' && (i == 0 || exp[i - 1] != '$') &&
                    exp[i + 1] == '$')
                    return;
            }
            if (cal() == tg) {
                string t;
                for (int i = 0; i < el; i++) {
                    if (exp[i] != '$')
                        t += exp[i];
                }
                ans.push_back(t);
            }
            return;
        }
        for (int i = 0; i < 4; i++) {
            exp[pos] = op[i];
            dfs(pos + 2);
        }
    }
    vector<string> addOperators(string num, int target) {
        l = num.size();
        el = num.size() * 2 - 1;
        tg = target;
        exp = string(el, '0');
        for (int i = 0; i < l; i++) {
            exp[i * 2] = num[i];
        }
        dfs(1);
        return ans;
    }
};