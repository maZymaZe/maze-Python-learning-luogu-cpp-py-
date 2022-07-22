class Solution {
   public:
    bool canTransform(string& start, string& target) {
        auto s = start, t = target;
        s.erase(remove(s.begin(), s.end(), 'X'), s.end());
        t.erase(remove(t.begin(), t.end(), 'X'), t.end());
        if (s != t)
            return false;
        for (int i = 0, j = 0; i < start.length(); ++i) {
            if (start[i] == 'X')
                continue;
            while (target[j] == 'X')
                ++j;
            if (i != j && (start[i] == 'L') != (i > j))
                return false;
            ++j;
        }
        return true;
    }
};
