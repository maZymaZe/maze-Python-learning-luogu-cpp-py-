class Solution {
   public:
    stack<long long> num, op;
    int calculate(string s) {
        long long l = s.length(), p = 0, f = 1, d = 0;
        while (p < l) {
            if (s[p] >= '0' && s[p] <= '9') {
                long long tmp = 0;
                while (p < l && s[p] >= '0' && s[p] <= '9') {
                    tmp = tmp * 10 + s[p] - '0';
                    p++;
                }
                if (f == 2)
                    tmp *= d, d = 0, f = 0;
                num.push(tmp);

                f = 0;
            } else if (s[p] == ' ')
                p++;
            else if (s[p] == '+' || s[p] == '-') {
                if (f == 1) {
                    d = (s[p] == '+') ? 1 : -1;
                    f = 2;
                    p++;
                    continue;
                }

                if (op.empty() || op.top() <= 0) {
                    op.push((s[p] == '+') ? 1 : 2);
                } else {
                    while (!op.empty() && op.top() > 0) {
                        long long a = num.top();
                        num.pop();
                        long long b = num.top();
                        num.pop();
                        num.push((op.top() == 1) ? a + b : b - a);
                        op.pop();
                    }
                    op.push((s[p] == '+' ? 1 : 2));
                }
                p++;
                f = 0;
            } else if (s[p] == '(') {
                int fl = 0;
                if (f == 2 && d == -1)
                    fl = -1;
                f = 1;
                op.push(fl);
                p++;
            } else if (s[p] == ')') {
                while (op.top() > 0) {
                    long long a = num.top();
                    num.pop();
                    long long b = num.top();
                    num.pop();
                    num.push((op.top() == 1) ? a + b : b - a);
                    op.pop();
                }
                if (op.top() == -1)
                    num.top() *= -1;
                op.pop();
                p++;
                f = 0;
            }
        }
        while (!op.empty() && op.top() > 0) {
            long long a = num.top();
            num.pop();
            long long b = num.top();
            num.pop();
            num.push((op.top() == 1) ? a + b : b - a);
            op.pop();
        }
        return num.top();
    }
};