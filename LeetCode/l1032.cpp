struct TRIENODE {
    int nx[26];
    bool valid;
    TRIENODE() {
        for (int i = 0; i < 26; i++)
            nx[i] = 0;
        valid = false;
    }
};
class StreamChecker {
   public:
    vector<TRIENODE> trie;
    list<char> buffer;
    void initTrie() {
        trie.clear();
        trie.push_back(TRIENODE());
    }
    void insert(const string& s) {
        int p = 0;
        for (auto c : s) {
            if (!trie[p].nx[c - 'a']) {
                trie[p].nx[c - 'a'] = trie.size();
                trie.push_back(TRIENODE());
            }
            p = trie[p].nx[c - 'a'];
        }
        trie[p].valid = 1;
    }
    StreamChecker(vector<string>& words) {
        initTrie();
        for (auto& s : words) {
            reverse(s.begin(), s.end());
            insert(s);
        }
    }

    bool query(char letter) {
        buffer.push_front(letter);
        if (buffer.size() > 200)
            buffer.pop_back();
        int p = 0;
        for (auto c : buffer) {
            if (!trie[p].nx[c - 'a'])
                return false;
            p = trie[p].nx[c - 'a'];
            if (trie[p].valid)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */