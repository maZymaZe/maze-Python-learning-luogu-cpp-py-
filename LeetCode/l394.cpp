class Solution {
public:
    string decodeString(string s) {
        stack<int> lf;
        int i = 0;
        while (i != s.size()) {
            if (s[i] == '[') {
                s = s.substr(0, i) + s.substr(i + 1, s.size());
                lf.push(i);
            }
            if (s[i] == ']') {
                int p = lf.top();
                lf.pop();
                int x = 0, g = p - 1;
                while (s[g] <= '9' && s[g] >= '0'&&(lf.empty()||g>=lf.top())) {
                    x = x + (s[g] - '0') * pow(10, p - g - 1);
                    g--;
                    if (g < 0) break;
                }
                string t = s.substr(p, i - p);
                string o;
                if (g >= 0) o = s.substr(0, g + 1);
                string e = s.substr(i + 1, s.size());
                for (int j = 1; j <= x; j++) {
                    o = o + t;
                }
                i = o.size() - 1;
                s = o + e;
            }
            i++;
        }
        return s;
    }
};