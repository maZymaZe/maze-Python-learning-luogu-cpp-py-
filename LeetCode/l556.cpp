class Solution {
   public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.size();
        if (l < 2)
            return -1;
        int i = l - 2;
        while (i >= 0) {
            if (s[i] < s[i + 1])
                break;
            i--;
        }
        if (i < 0)
            return -1;
        int j = l - 1;
        while (j >= 0) {
            if (s[j] > s[i])
                break;
            j--;
        }
        swap(s[j], s[i]);
        reverse(s.begin() + i + 1, s.end());
        long long rs = stoll(s);
        if (rs > INT_MAX)
            return -1;
        return rs;
    }
};