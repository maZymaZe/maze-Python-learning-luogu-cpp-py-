
struct TRIE {
    int nx[26];
    bool ex;
};
class Solution {
   public:
    int root = 1;
    vector<TRIE> tr;
    void TRIEINIT() {
        tr.resize(2);
        root = 1;
    }
    string find(const string& x) {
        int p = root, i = 0, l = x.size();
        while (p < tr.size() & i < l) {
            if (tr[p].nx[x[i] - 'a']) {
                p = tr[p].nx[x[i] - 'a'];
                if (tr[p].ex) {
                    return x.substr(0, i + 1);
                }
                i++;
            } else {
                return x;
            }
        }
        return x;
    }
    void insert(const string& x) {
        int p = root, i = 0, l = x.size();
        while (i < l) {
            if (tr[p].nx[x[i] - 'a']) {
                p = tr[p].nx[x[i] - 'a'];
                i++;
            } else {
                tr.push_back(TRIE());
                tr[p].nx[x[i] - 'a'] = tr.size() - 1;
                p = tr.size() - 1;
                i++;
            }
        }
        tr[p].ex = true;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        int bg = 0, p = 0, l = dictionary.size(), len = sentence.size();
        TRIEINIT();
        for (int i = 0; i < l; i++)
            insert(dictionary[i]);
        string ans;
        for (int i = 0; i < len; i++) {
            if (sentence[i] == ' ') {
                ans += find(sentence.substr(bg, i - bg));
                ans += ' ';
                bg = i + 1;
            }
        }
        ans += find(sentence.substr(bg, len));
        return ans;
    }
};