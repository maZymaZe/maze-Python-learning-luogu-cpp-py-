struct Trie {
    Trie* child[26];
    string word;
    Trie() {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
    void add(string& s) {
        Trie* p = this;
        for (auto c : s) {
            if (!p->child[c - 'a'])
                p->child[c - 'a'] = new Trie();
            p = p->child[c - 'a'];
        }
        p->word = s;
    }
    void find(vector<vector<char>>& board,
              vector<vector<int>>& mark,
              int x,
              int y,
              Trie* p,
              vector<string>& ans) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            mark[x][y] || p->child[board[x][y] - 'a'] == nullptr) {
            return;
        }
        p = p->child[board[x][y] - 'a'];
        mark[x][y] = 1;
        if (p->word.size()) {
            ans.push_back(p->word);
            p->word = "";
        }
        find(board, mark, x - 1, y, p, ans);
        find(board, mark, x, y - 1, p, ans);
        find(board, mark, x, y + 1, p, ans);
        find(board, mark, x + 1, y, p, ans);
        mark[x][y] = 0;
    }
};
class Solution {
   public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        vector<string> ans;
        Trie* root = new Trie();
        for (auto& x : words)
            root->add(x);
        int x = board.size(), y = board[0].size();
        vector<vector<int>> mark(x, vector<int>(y));
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                root->find(board, mark, i, j, root, ans);
            }
        }
        return ans;
    }
};
