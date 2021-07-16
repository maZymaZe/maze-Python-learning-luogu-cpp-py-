class Solution {
   public:
    string maskPII(string s) {
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] == '@') {
                for (int j = 0; j < l; j++) {
                    if (s[j] <= 'Z' && s[j] >= 'A') {
                        s[j] = s[j] - 'A' + 'a';
                    }
                }
                
                return s.substr(0,1)+"*****"+s.substr(i-1,l);
            }
        }
        int cc = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] <= '9' && s[i] >= '0')
                cc++;
        }
        if (cc > 10) {
            int cnt = 0, p;
            for (int i = l - 1; i >= 0; i--) {
                if (s[i] <= '9' && s[i] >= '0') {
                    cnt++;
                }
                if (cnt == 10) {
                    p = i;
                    string result;
                    result += "+";
                    for (int j = 0; j < p; j++) {
                        if (s[j] <= '9' && s[j] >= '0') {
                            result += "*";
                        }
                    }
                    result += "-";
                    cnt = 0;
                    for (int k = p; k < l; k++) {
                        if (s[k] <= '9' && s[k] >= '0') {
                            if (cnt >= 6)
                                result.push_back(s[k]);
                            else
                                result.push_back('*');
                            cnt++;
                            if (cnt == 3 || cnt == 6)
                                result += "-";
                        }
                    }
                    return result;
                }
            }
        }

        int cnt = 0;
        string result;
        for (int i = 0; i < l; i++) {
            if (s[i] <= '9' && s[i] >= '0') {
                if (cnt >= 6)
                    result.push_back(s[i]);
                else
                    result.push_back('*');
                cnt++;
                if (cnt == 3 || cnt == 6)
                    result += "-";
            }
        }
        return result;
    }
};