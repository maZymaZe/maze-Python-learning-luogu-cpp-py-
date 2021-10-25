class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        int l = tokens.size();
        for (int i = 0; i < l; i++) {
            if (tokens[i][0] == '+' && tokens[i].size() == 1) {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a + b);
            } else if (tokens[i][0] == '-' && tokens[i].size() == 1) {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b - a);
            } else if (tokens[i][0] == '*' && tokens[i].size() == 1) {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(a * b);
            } else if (tokens[i][0] == '/' && tokens[i].size() == 1) {
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                s.push(b / a);
            } else {
                long long t = (long long)stoi((string)tokens[i]);
                s.push(t);
            }
        }
        return s.top();
    }
};