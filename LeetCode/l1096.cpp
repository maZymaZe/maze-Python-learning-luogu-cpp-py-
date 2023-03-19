class Solution {
   public:
    vector<string> braceExpansionII(string expression) {
        vector<char> op;
        vector<set<string>> stk;
        auto ope = [&]() {
            int l = stk.size() - 2, r = stk.size() - 1;
            if (op.back() == '+') {
                stk[l].merge(stk[r]);
            } else {
                set<string> tmp;
                for (auto& lf : stk[l]) {
                    for (auto& rg : stk[r]) {
                        tmp.insert(lf + rg);
                    }
                }
                stk[l] = move(tmp);
            }
            op.pop_back();
            stk.pop_back();
        };
        int len = expression.size();
        for (int i = 0; i < len; i++) {
            if (expression[i] == ',') {
                while (op.size() && op.back() == '*')
                    ope();
                op.push_back('+');

            } else if (expression[i] == '{') {
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                op.push_back('{');
            } else if (expression[i] == '}') {
                while (op.size() && op.back() != '{')
                    ope();
                op.pop_back();
            } else {
                if (i > 0 &&
                    (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }
        while (op.size())
            ope();
        return {stk.back().begin(), stk.back().end()};
    }
};