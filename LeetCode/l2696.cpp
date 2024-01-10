class Solution {
   public:
    int minLength(string s) {
        list<char> ls;
        ls.push_back('t');
        for (char c : s)
            ls.push_back(c);
        ls.push_back('t');
        auto it = ls.begin();
        auto it2 = it;
        ++it2;
        while (it2 != ls.end()) {
            if ((*it == 'A' && *it2 == 'B') || (*it == 'C' && *it2 == 'D')) {
                auto nit = it;
                nit--;
                ls.erase(it);
                ls.erase(it2);
                it = nit;
                nit++;
                it2 = nit;
            } else {
                ++it, ++it2;
            }
        }
        return ls.size() - 2;
    }
};