class Solution {
   public:
    string pushDominoes(string dominoes) {
        vector<int> ll[2], rr[2];
        int op = 0, l = dominoes.size();
        for (int i = 0; i < l; i++) {
            if (dominoes[i] == 'L')
                ll[op].push_back(i);
            else if (dominoes[i] == 'R')
                rr[op].push_back(i);
        }
        while (!ll[op].empty() || !rr[op].empty()) {
            while (!ll[op].empty()) {
                int x = ll[op].back();
                ll[op].pop_back();
                if (x != 0 && dominoes[x - 1] == '.' &&
                    !(x > 1 && dominoes[x - 2] == 'R')) {
                    ll[!op].push_back(x - 1);
                }
            }
            while (!rr[op].empty()) {
                int x = rr[op].back();
                rr[op].pop_back();
                if (x + 1 < l && dominoes[x + 1] == '.' &&
                    !(x + 2 < l && dominoes[x + 2] == 'L')) {
                    rr[!op].push_back(x + 1);
                }
            }
            for (const auto& i : ll[!op]) {
                dominoes[i] = 'L';
            }
            for (const auto& i : rr[!op]) {
                dominoes[i] = 'R';
            }
            op = (!op);
        }
        return dominoes;
    }
};