class Trie {
   public:
    /** Initialize your data structure here. */
    vector<vector<int>> mempol;
    unordered_set<int> valid;
    Trie() { mempol.push_back(vector<int>(26)); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int p = 0, l = word.size();
        for (int i = 0; i < l; i++) {
            if (mempol[p][word[i] - 'a']) {
                p = mempol[p][word[i] - 'a'];
            } else {
                int np = mempol.size();
                mempol.push_back(vector<int>(26));
                mempol[p][word[i] - 'a'] = np;
                p = np;
            }
            if (i == l - 1)
                valid.insert(p);
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0, l = word.size();
        for (int i = 0; i < l; i++) {
            if (mempol[p][word[i] - 'a']) {
                p = mempol[p][word[i] - 'a'];
            } else {
                return false;
            }
        }
        return valid.count(p);
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        int p = 0, l = prefix.size();
        for (int i = 0; i < l; i++) {
            if (mempol[p][prefix[i] - 'a']) {
                p = mempol[p][prefix[i] - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */