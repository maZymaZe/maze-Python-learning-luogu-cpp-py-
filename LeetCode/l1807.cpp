class Solution {
   public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int p = 0, l = s.length(), t = 0, b = 0;
        unordered_map<string, string> kn;
        for (auto& it : knowledge)
            kn[it[0]] = it[1];
        string answer;
        while (p < l) {
            if (t) {
                if (s[p] == ')') {
                    string ts = s.substr(b + 1, p - b - 1);
                    if (kn.count(ts))
                        answer += kn[ts];
                    else
                        answer += '?';
                    t = 0;
                }
            } else {
                if (s[p] == '(')
                    b = p, t = 1;
                else
                    answer += s[p];
            }
            p++;
        }
        return answer;
    }
};