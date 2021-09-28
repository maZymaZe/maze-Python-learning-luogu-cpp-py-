class Solution {
   public:
    unordered_map<int, int> V;
    int nc, nr, rem;
    mt19937 rng{random_device{}()};
    int randint(int b) {
        uniform_int_distribution<int> uni(0, b);
        return uni(rng);
    }
    Solution(int m, int n) { nr = m, nc = n, rem = m * n; }

    vector<int> flip() {
        int r = randint(--rem);
        int x = V.count(r) ? V[r] : V[r] = r;
        V[r] = V.count(rem) ? V[rem] : V[rem] = rem;
        return {x / nc, x % nc};
    }

    void reset() {
        V.clear();
        rem = nr * nc;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */