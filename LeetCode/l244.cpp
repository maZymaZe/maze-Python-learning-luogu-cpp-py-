class WordDistance {
   public:
    unordered_map<string, int> ck;
    vector<int> op;
    int ep = 0;
    WordDistance(vector<string>& wordsDict) {
        int l = wordsDict.size();
        op.resize(l);
        for (int i = 0; i < l; i++) {
            if (ck.count(wordsDict[i])) {
                op[i] = ck[wordsDict[i]];
            } else {
                ck[wordsDict[i]] = ++ep;
                op[i] = ck[wordsDict[i]];
            }
        }
    }

    int shortest(string word1, string word2) {
        int w1 = ck[word1], w2 = ck[word2];
        int l = op.size();
        int p = 0, q = 0;
        while (w1 != op[p])
            p++;
        while (w2 != op[q])
            q++;
        int ans = abs(p - q);
        while (p < l && q < l) {
            if (p < q) {
                p++;
                while (p < l && w1 != op[p])
                    p++;
                if (p == l)
                    break;
            } else {
                q++;
                while (q < l && w2 != op[q])
                    q++;
                if (q == l)
                    break;
            }
            ans = min(ans, abs(p - q));
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */