class Solution {
   public:
    stack<long long> num, op;
    int calculate(string s) {
        int l = s.length(), p = 0;
        while (p < l) {
            if (s[p] >= '0' && s[p] <= '9') {
                long long tmp = 0;
                while (p < l && s[p] >= '0' && s[p] <= '9') {
                    tmp = tmp * 10 + s[p] - '0';
                    p++;
                }
                num.push(tmp);
            } else if (s[p] == ' ')
                p++;
            else if (s[p] == '+') {
                while (!op.empty()) {
                    long long a = num.top();
                    num.pop();
                    long long b = num.top();
                    num.pop();
                    if (op.top() == 1)
                        num.push(a + b);
                    else if (op.top() == 2)
                        num.push(b - a);
                    else if (op.top() == 3)
                        num.push(a * b);
                    else if (op.top() == 4)
                        num.push(b / a);
                    op.pop();
                }
                op.push(1);
                p++;
            } else if (s[p] == '-') {
                while (!op.empty()) {
                    long long a = num.top();
                    num.pop();
                    long long b = num.top();
                    num.pop();
                    if (op.top() == 1)
                        num.push(a + b);
                    else if (op.top() == 2)
                        num.push(b - a);
                    else if (op.top() == 3)
                        num.push(a * b);
                    else if (op.top() == 4)
                        num.push(b / a);
                    op.pop();
                }
                op.push(2);
                p++;
            } else if (s[p] == '*') {
                while (!op.empty() && op.top() > 2) {
                    long long a = num.top();
                    num.pop();
                    long long b = num.top();
                    num.pop();
                    if (op.top() == 3)
                        num.push(a * b);
                    else if (op.top() == 4)
                        num.push(b / a);
                    op.pop();
                }
                op.push(3);
                p++;
            } else if (s[p] == '/') {
                while (!op.empty() && op.top() > 2) {
                    long long a = num.top();
                    num.pop();
                    long long b = num.top();
                    num.pop();
                    if (op.top() == 3)
                        num.push(a * b);
                    else if (op.top() == 4)
                        num.push(b / a);
                    op.pop();
                }
                op.push(4);
                p++;
            }
        }
        while (!op.empty()) {
            long long a = num.top();
            num.pop();
            long long b = num.top();
            num.pop();
            if (op.top() == 1)
                num.push(a + b);
            else if (op.top() == 2)
                num.push(b - a);
            else if (op.top() == 3)
                num.push(a * b);
            else if (op.top() == 4)
                num.push(b / a);
            op.pop();
        }
    
        return num.top();
    }


};