class CombinationIterator {
   public:
    vector<char> vc, ab;
    vector<int> ps;
    int l, cl;
    bool hn;
    CombinationIterator(string characters, int combinationLength) {
        l = characters.size();
        ab.resize(l);
        for (int i = 0; i < l; i++) {
            ab[i] = characters[i];
        }
        cl = combinationLength;
        vc.resize(cl);
        ps.resize(cl);
        for (int i = 0; i < cl; i++) {
            vc[i] = ab[i];
            ps[i] = i;
        }
        hn = (l != cl);
    }

    string next() {
        string result;
        for (int i = 0; i < cl; i++)
            result.push_back(vc[i]);
        for (int i = 1; i <= cl; i++) {
            if (ps[cl - i] != l - i) {
                ps[cl - i]++;
                vc[cl - i] = ab[ps[cl - i]];
                for (int j = cl - i + 1; j < cl; j++) {
                    ps[j] = ps[j - 1] + 1;
                    vc[j] = ab[ps[j]];
                }
                return result;
            }
        }
        hn = false;
        return result;
    }

    bool hasNext() { return hn; }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */