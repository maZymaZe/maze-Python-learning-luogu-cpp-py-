class Solution {
   public:
    string reformatNumber(string number) {
        string digits;
        for (char ch : number) {
            if (isdigit(ch)) {
                digits.push_back(ch);
            }
        }

        int n = digits.size();
        int pt = 0;
        string ans;
        while (n) {
            if (n > 4) {
                ans += digits.substr(pt, 3) + "-";
                pt += 3;
                n -= 3;
            } else {
                if (n == 4) {
                    ans +=
                        digits.substr(pt, 2) + "-" + digits.substr(pt + 2, 2);
                } else {
                    ans += digits.substr(pt, n);
                }
                break;
            }
        }
        return ans;
    }
};
