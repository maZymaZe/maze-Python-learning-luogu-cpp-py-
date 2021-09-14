struct cmp {
    bool operator()(int a, int b) { return a % 3 > b % 3; }
};

class Solution {
   public:
    priority_queue<int, vector<int>, cmp> ct;

    int strongPasswordChecker(string password) {
        int l = password.size(), tp = 0;
        for (int i = 0; i < l; i++) {
            if (password[i] >= 'a' && password[i] <= 'z') {
                tp++;
                break;
            }
        }
        for (int i = 0; i < l; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                tp++;
                break;
            }
        }
        for (int i = 0; i < l; i++) {
            if (password[i] >= '0' && password[i] <= '9') {
                tp++;
                break;
            }
        }
        for (int i = 0, j; i < l; i = j) {
            j = i + 1;
            while (password[j] == password[i])
                j++;
            if (j - i > 2)
                ct.push(j - i);
        }

        int ans = 0;
        while (l > 20) {
            ++ans;
            --l;
            if (!ct.empty()) {
                int t = ct.top();
                t--;
                ct.pop();
                if (t > 2)
                    ct.push(t);
            }
        }

        while (l < 6 || !ct.empty()) {
            ++ans;
            ++l;
            if (!ct.empty()) {
                int t = ct.top();
                t -= 3;
                ct.pop();
                if (t > 2)
                    ct.push(t);
            }
            if (tp < 3)
                tp++;
        }
        ans += 3 - tp;
        return ans;
    }
};