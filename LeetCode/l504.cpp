class Solution {
   public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        int g = 0;
        if (num < 0)
            g = 1, num = -num;
        vector<int> v;
        while (num)
            v.push_back(num % 7), num /= 7;
        reverse(v.begin(), v.end());
        string ans;
        if (g)
            ans += '-';
        for (int x : v)
            ans += to_string(x);
        return ans;
    }
};