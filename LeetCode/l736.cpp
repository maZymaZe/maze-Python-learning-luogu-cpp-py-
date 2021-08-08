class Solution {
   public:
    map<string, int> vars;
    const int INF = 0x3f3f3f3f;
    void get_token(string& e, vector<string>& res) {
        int cnt = 0, start = 0, len = e.size();
        if (e[0] == '(')
            start = 1;
        for (int i = start; i < len; i++) {
            if (cnt == 0 && (e[i] == ' ' || e[i] == ')')) {
                res.push_back(e.substr(start, i - start));
                start = i + 1;
            }
            if (e[i] == '(')
                cnt++;
            else if (e[i] == ')')
                cnt--;
        }
    }
    int evaluate(string expression) {
        map<string, int> globalvars;
        vector<string> tokens;
        get_token(expression, tokens);
        string cmd = tokens[0];
        int res = 0, len = tokens.size();
        if (cmd == "let") {
            int i = 1;
            for (; i + 1 < len; i += 2) {
                string v1 = tokens[i], e1 = tokens[i + 1];
                if (globalvars.find(v1) == globalvars.end()) {
                    if (vars.find(v1) != vars.end()) {
                        globalvars[v1] = vars[v1];
                    } else
                        globalvars[v1] = INF;
                }

                if (e1[0] == '(') {
                    vars[v1] = evaluate(e1);
                } else if ((e1[0] >= '0' && e1[0] <= '9') ||
                           (e1.size() > 1 && e1[1] >= '0' && e1[1] <= '9')) {
                    vars[v1] = stoi(e1);
                } else
                    vars[v1] = vars[e1];
            }
            string expr = tokens[i];
            if (expr[0] == '(') {
                res = evaluate(expr);
            } else {
                if (vars.find(expr) != vars.end())
                    res = vars[expr];
                else
                    res = stoi(expr);
            }
        } else if (cmd == "add" || cmd == "mult") {
            string v1 = tokens[1], v2 = tokens[2];
            int vint1, vint2;
            if (v1[0] == '(')
                vint1 = evaluate(v1);
            else if (vars.find(v1) != vars.end())
                vint1 = vars[v1];
            else
                vint1 = stoi(v1);

            if (v2[0] == '(')
                vint2 = evaluate(v2);
            else if (vars.find(v2) != vars.end())
                vint2 = vars[v2];
            else
                vint2 = stoi(v2);

            if (cmd == "add")
                res = vint1 + vint2;
            else if (cmd == "mult")
                res = vint1 * vint2;
        }

        for (auto it = globalvars.begin(); it != globalvars.end(); ++it) {
            if (it->second == INF)
                vars.erase(it->first);
            else
                vars[it->first] = it->second;
        }
        return res;
    }
};