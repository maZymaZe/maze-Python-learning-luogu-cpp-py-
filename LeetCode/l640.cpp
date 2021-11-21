class Solution {
   public:
    string lexp, rexp;
    pair<int, int> evl(string& x) {
        int p = 0, q = 0, l = x.size();
        int r1 = 0, r2 = 0, a, b, f;
        while (p < l) {
            q = p + 1;
            if (x[p] == '+')
                f = 1;
            else
                f = -1;
            while (q < l && (x[q] != '+' && x[q] != '-')) {
                q++;
            }
            if (x[q - 1] == 'x') {
                if (q == p + 2) {
                    b = 1;
                } else
                    b = stoi(x.substr(p + 1, q - p - 2));
                r2 += f * b;
            } else {
                a = stoi(x.substr(p + 1, q - p - 1));
                r1 += f * a;
            }
            p = q;
        }
        return {r1, r2};
    }
    string solveEquation(string equation) {
        int len = equation.length();

        for (int i = 0; i < len; i++) {
            if (equation[i] == '=') {
                lexp = equation.substr(0, i);
                rexp = equation.substr(i + 1, len);
            }
        }
        if (lexp[0] != '+' && lexp[0] != '-')
            lexp = '+' + lexp;
        if (rexp[0] != '+' && rexp[0] != '-')
            rexp = '+' + rexp;
        pair<int, int> lf = evl(lexp), rg = evl(rexp);
        if (lf.second == rg.second) {
            if (lf.first == rg.first) {
                return "Infinite solutions";
            } else
                return "No solution";
        }

        int fz = rg.first - lf.first;
        int fm = lf.second - rg.second;
        return "x=" + to_string(fz / fm);
    }
};