class Solution {
   public:
    string minRemoveToMakeValid(string s) {
        int l = s.size();
        vector<int> v(l);
        stack<int> st;
        for (int i = 0; i < l; i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (s[i] == '(') {
                    st.push(i);
                } else {
                    if (!st.empty()) {
                        v[i] = v[st.top()] = 1;
                        st.pop();
                    }
                }
            }
        }
        string ans;
        for (int i = 0; i < l; i++) {
            if (s[i] == '(' || s[i] == ')') {
                if (v[i])
                    ans += s[i];
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};