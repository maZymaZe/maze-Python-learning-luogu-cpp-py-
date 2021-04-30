class Solution {
   public:
    long double trans(string& x) {
        long double result = 0;
        int l = x.length(), a = -1, b = -1, c = -1, t = 1, tt = 0;
        for (int i = 0; i < l; i++) {
            if (x[i] == '.') {
                result += stoi(x.substr(0, i));
                a = i + 1;
            } else if (x[i] == '(') {
                int len1 = i - a;
                b = i + 1;
                if (len1 == 0)
                    continue;
                for (int i = 1; i <= len1; i++)
                    t *= 10;
                result += (long double)stoi(x.substr(a, len1)) / t;

            } else if (x[i] == ')') {
                int len2 = i - b;
                for (int i = 1; i <= len2; i++) {
                    tt = tt * 10 + 9;
                }
                result += (long double)stoi(x.substr(b, len2)) / t / tt;
            }
        }
        if (a == -1) {
            result += (long double)stoi(x);
        } else if (b == -1) {
            int len1 = l - a;
            if (len1) {
                for (int i = 1; i <= len1; i++)
                    t *= 10;
                result += (long double)stoi(x.substr(a, len1)) / t;
            }
        }
        return result;
    }
    bool isRationalEqual(string s, string t) {
        return fabs(trans(s) - trans(t)) < 1e-8;
    }
};