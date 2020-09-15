class Solution {
   public:
    string reverseParentheses(string s) {
        int l = s.size();
        stack<int> stk;
        vector<int> v(l);
        string ret;
        for (int i = 0; i < l; i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                v[j] = i, v[i] = j;
            }
        }
        for(int i=0,d=1;i<l;i+=d){
            if(s[i]=='('||s[i]==')'){
                i=v[i],d=-d;
            }
            else ret+=s[i];
        }
        return ret;
    }
};