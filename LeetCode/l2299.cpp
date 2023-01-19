class Solution {
   public:
    bool strongPasswordCheckerII(string password) {
        int l = password.size();
        string sp = "!@#$%^&*()-+";
        int cnt[300] = {0};
        if (l < 8)
            return false;
        for (auto c : password)
            cnt[c]++;
        int t = 0;
        for (int i = 'a'; i <= 'z'; i++)
            t += cnt[i];
        if (!t)
            return false;
        t = 0;
        for (int i = 'A'; i <= 'Z'; i++)
            t += cnt[i];
        if (!t)
            return false;
        t = 0;
        for (int i = '0'; i <= '9'; i++)
            t += cnt[i];
        if (!t)
            return false;
        t = 0;
        for (auto i : sp)
            t += cnt[i];
        if (!t)
            return false;
        for (int i = 1; i < l; i++) {
            if (password[i] == password[i - 1])
                return false;
        }
        return true;
    }
};