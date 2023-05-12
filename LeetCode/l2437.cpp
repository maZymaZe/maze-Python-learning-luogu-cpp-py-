class Solution {
public:
    bool check(const string &time) {
        int hh = stoi(time);
        int mm = stoi(time.substr(3));
        if (hh < 24 && mm < 60) {
            return true;
        } else {
            return false;
        }
    }

    int countTime(string time) {
        int res = 0;
        function<void(int)> dfs = [&](int pos) {
            if (pos == time.size()) {
                if (check(time)) {
                    res++;
                }
                return;
            }
            if (time[pos] == '?') {
                for (int i = 0; i <= 9; i++) {
                    time[pos] = '0' + i;
                    dfs(pos + 1);
                    time[pos] = '?';
                }
            } else {
                dfs(pos + 1);
            }
        };
        dfs(0);
        return res;
    }
};

