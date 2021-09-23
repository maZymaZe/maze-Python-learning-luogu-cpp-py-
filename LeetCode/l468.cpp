class Solution {
   public:
    string validIPAddress(string IP) {
        int l = IP.length();
        int cd = 0, cm = 0;
        for (int i = 0; i < l; i++) {
            if (IP[i] == '.')
                cd++;
            if (IP[i] == ':')
                cm++;
        }
        if (cd == 0 && cm == 7) {
            int s = 0;
            for (int i = 0; i < l; i++) {
                if (IP[i] == ':' || (IP[i] >= '0' && IP[i] <= '9') ||
                    (IP[i] >= 'a' && IP[i] <= 'f') ||
                    (IP[i] >= 'A' && IP[i] <= 'F')) {
                    if (IP[i] == ':') {
                        if (i > s + 4 || i == s)
                            return "Neither";
                        s = i + 1;
                    }
                } else
                    return "Neither";
            }

            if (s + 3 < l - 1 || s == l)
                return "Neither";
            return "IPv6";
        } else if (cd == 3 && cm == 0) {
            int s = 0;
            for (int i = 0; i < l; i++) {
                if (IP[i] == '.' || (IP[i] >= '0' && IP[i] <= '9')) {
                    if (IP[i] == '.') {
                        if (i == s || (i - s > 1 && IP[s] == '0') || i - s > 5)
                            return "Neither";
                        int w = stoi(IP.substr(s, i - s));
                        if (w > 255)
                            return "Neither";
                        s = i + 1;
                    }
                } else
                    return "Neither";
            }
            if (l - s == 0)
                return "Neither";
            if (l - s > 1 && IP[s] == '0' || l - s > 5)
                return "Neither";
            int w = stoi(IP.substr(s, l - s));

            if (w > 255)
                return "Neither";
            return "IPv4";
        }
        return "Neither";
    }
};