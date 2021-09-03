struct trie {
    int nx[26];
    bool valid;
    trie() {
        memset(nx, 0, sizeof(nx));
        valid = false;
    }
};
class WordDictionary {
   public:
    /** Initialize your data structure here. */
    vector<trie> tree;

    WordDictionary() { tree.push_back(trie()); }

    void addWord(string word) {
        int p = 0;
        int l = word.length();
        for (int i = 0; i < l; i++) {
            if (tree[p].nx[word[i] - 'a'] == 0) {
                tree.push_back(trie());
                tree[p].nx[word[i] - 'a'] = tree.size() - 1;
            }
            p = tree[p].nx[word[i] - 'a'];
        }
        tree[p].valid = 1;
    }
    bool ck(string& word, int pos, int root) {
        if (pos == word.size()) {
            return tree[root].valid;
        }
        if (word[pos] == '.') {
            bool ret = 0;
            for (int i = 0; i < 26; i++) {
                if (tree[root].nx[i]) {
                    ret |= ck(word, pos + 1, tree[root].nx[i]);
                }
            }
            return ret;
        }
        if (tree[root].nx[word[pos] - 'a']) {
            return ck(word, pos + 1, tree[root].nx[word[pos] - 'a']);
        }
        return false;
    }
    bool search(string word) { return ck(word, 0, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */