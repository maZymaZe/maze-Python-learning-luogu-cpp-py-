class Solution {
   public:
    bool isValid(string s) {
        stack<char> t;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (t.empty() || t.top() != s[i]) {
                t.push('c');
                t.push('b');
                t.push('a');
            }
            if (t.top() != s[i]) {
                return false;
            } else
                t.pop();
        }
        return t.empty();
    }
};