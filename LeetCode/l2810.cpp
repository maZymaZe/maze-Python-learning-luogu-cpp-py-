class Solution {
   public:
    string finalString(string s) {
        int g = 1;
        list<char> ls;
        for (char c : s) {
            if (c == 'i')
                g ^= 1;
            else {
                if (g)
                    ls.push_back(c);
                else
                    ls.push_front(c);
            }
        }
        auto ret = string(ls.begin(), ls.end());
        if (!g)
            reverse(ret.begin(), ret.end());
        return ret;
    }
};