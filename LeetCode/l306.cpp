class Solution {
   public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        long long pre = 0;
        for (int i = 0; i < n - 2; i++) {
            if (i == 1 && num[0] == '0')
                return false;
            pre = pre * 10 + num[i] - '0';
            long long cur = 0;
            for (int j = i + 1; j < n - 1; j++) {
                cur = cur * 10 + num[j] - '0';
                if (j > i + 1 && num[i + 1] == '0')
                    break;
                if (ck(num, n, j + 1, cur, pre + cur))
                    return true;
            }
        }
        return false;
    }
    bool ck(string& num, int n, int start, long long pre, long long cur) {
        for (int i = start; i < n;) {
            string str = to_string(cur);
            if (num.find(str, i) != i)
                return false;
            i += str.size();
            long long temp = cur;
            cur += pre;
            pre = temp;
        }
        return true;
    }
};