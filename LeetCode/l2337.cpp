class Solution {
   public:
    bool canChange(string start, string target) {
        int l = start.length();
        int p1 = 0, p2 = 0;
        while (p1 < l && start[p1] == '_')
            p1++;
        while (p2 < l && target[p2] == '_')
            p2++;
        if (p1 == l && p2 == l)
            return true;
        while (p1 < l && p2 < l) {
            if (p1 < l && p2 < l && start[p1] == target[p2]) {
                if (start[p1] == 'L' && p1 < p2) {
                    return false;
                } else if (start[p1] == 'R' && p1 > p2) {
                    return false;
                }
                p1++, p2++;
            } else
                return false;
            while (p1 < l && start[p1] == '_')
                p1++;
            while (p2 < l && target[p2] == '_')
                p2++;
            if (p1 == l && p2 == l)
                return true;
        }
        return false;
    }
};