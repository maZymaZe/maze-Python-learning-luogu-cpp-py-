class Solution {
   public:
    string fractionAddition(string expression) {
        if (expression[0] != '-')
            expression = '+' + expression;
        int p = 0, l = expression.size();
        long long tot = 0, bs = 362880, a, b;
        while (p < l) {
            char x = expression[p];
            if (p + 2 < l && expression[p + 1] == '1' &&
                expression[p + 2] == '0')
                a = 10, p += 2;
            else
                a = expression[p + 1] - '0', p += 1;
            if (p + 3 < l && expression[p + 2] == '1' &&
                expression[p + 3] == '0')
                b = 10, p += 4;
            else
                b = expression[p + 2] - '0', p += 3;
            if (x == '+') {
                tot += (bs / b * a);
            } else {
                tot -= (bs / b * a);
            }
        }
        if (tot == 0)
            return "0/1";
        string ans;
        if (tot < 0)
            tot = -tot, ans += '-';
        long long g = __gcd(bs, tot);
        tot /= g;
        bs /= g;
        ans += to_string(tot) + '/' + to_string(bs);
        return ans;
    }
};