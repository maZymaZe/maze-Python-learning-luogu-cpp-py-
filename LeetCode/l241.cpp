class Solution {
   public:
    bool isdigit(char c) { return c >= '0' && c <= '9'; }
    vector<int> work(int l, int r, string& input) {
        if(l>=r)return {};
        int t = 0;
        bool f = 0;
        vector<int> ret;
        vector<int> t1, t2;
        for (int i = l; i < r; i++) {
            if (!f && isdigit(input[i])) {
                t = t * 10 + input[i] - '0';
            } else {
                f=1;
                t1 = move(work(l, i, input));
                t2 = move(work(i + 1, r, input));
                if (input[i] == '+') {
                    int l1 = t1.size(), l2 = t2.size();
                    for (int k = 0; k < l1; k++) {
                        for (int j = 0; j < l2; j++) {
                            ret.push_back(t1[k] + t2[j]);
                        }
                    }
                }
                if (input[i] == '-') {
                    int l1 = t1.size(), l2 = t2.size();
                    for (int k = 0; k < l1; k++) {
                        for (int j = 0; j < l2; j++) {
                            ret.push_back(t1[k] - t2[j]);
                        }
                    }
                }
                if (input[i] == '*') {
                    int l1 = t1.size(), l2 = t2.size();
                    for (int k = 0; k < l1; k++) {
                        for (int j = 0; j < l2; j++) {
                            ret.push_back(t1[k] * t2[j]);
                        }
                    }
                }
            }
        }
        if(!f)return {t};
        return ret;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        int l = input.length();
        ans = move(work(0, l, input));
        return ans;
    }
};