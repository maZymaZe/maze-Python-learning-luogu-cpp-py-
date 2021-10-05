class Solution {
   public:
    stack<string> s;
    bool hsyg = 0;
    bool isValidTag(const string& name, bool isEnd = 0) {
        if (name.size() < 1 || name.size() > 9)
            return false;
        for (auto c : name) {
            if (!(c >= 'A' && c <= 'Z'))
                return false;
        }
        if (isEnd) {
            if (s.empty() || s.top() != name)
                return false;
            s.pop();
        } else
            hsyg = true, s.push(name);
        return true;
    }
    bool isValid(string code) {
        int n = code.size();
        if (n < 3 || code[n - 1] != '>' || code[0] != '<')
            return false;
        for (int i = 0; i < n; i++) {
            if (s.empty() && hsyg)
                return false;
            if (code[i] == '<') {
                int edx = 0;
                if (!s.empty() && code[i + 1] == '!') {
                    edx = code.find("]]>", i + 1);
                    if (edx == string::npos ||
                        code.find("[CDATA[", i + 2) != i + 2)
                        return false;
                    edx += 2;
                } else {
                    bool ise = 0;
                    if (code[i + 1] == '/')
                        ++i, ise = 1;
                    edx = code.find('>', i + 1);
                    if (edx == string::npos ||
                        !isValidTag(code.substr(i + 1, edx - i - 1), ise))
                        return false;
                }
                i = edx;
            }
        }
        return hsyg && s.empty();
    }
};