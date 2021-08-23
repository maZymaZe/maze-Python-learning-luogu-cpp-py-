class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int l = 0, len = words.size(), r = 1, tot = 0;
        vector<string> ans;
        while (l < len) {
            tot = words[l].size();
            while (r < len && tot + words[r].size() + 1 <= maxWidth) {
                tot += words[r].size() + 1;
                r++;
            }
            if (r < len) {
                r--;

                if (l == r) {
                    string line = words[l];
                    line += string(maxWidth - words[l].size(), ' ');

                    ans.push_back(line);
                } else {
                    int cl = 0;
                    for (int i = l; i <= r; i++) {
                        cl += words[i].size();
                    }
                    int rb = (maxWidth - cl) / (r - l);
                    int lc = (maxWidth - cl) % (r - l);

                    string line = words[l];
                    for (int i = 1; i <= lc; i++) {
                        line += string(rb + 1, ' ');
                        line += words[l + i];
                    }
                    for (int i = l + lc + 1; i <= r; i++) {
                        line += string(rb, ' ');
                        line += words[i];
                    }
                    ans.push_back(line);
                }
            } else {
                int u = maxWidth;
                string line = words[l];
                u -= words[l].size();
                for (int i = l + 1; i < len; i++) {
                    line += ' ';
                    line += words[i];
                    u -= words[i].size() + 1;
                }
                assert(u >= 0);
                line += string(u, ' ');
                ans.push_back(line);
            }
            l = r + 1;
            r = l + 1;
        }
        return ans;
    }
};