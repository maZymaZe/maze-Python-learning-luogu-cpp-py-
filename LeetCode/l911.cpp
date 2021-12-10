class TopVotedCandidate {
   public:
    vector<int> tp, tt;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> vc;
        vc[-1] = -1;
        int to = -1;
        for (auto& p : persons) {
            vc[p]++;
            if (vc[p] >= vc[to])
                to = p;
            tp.push_back(to);
        }
        tt = times;
    }

    int q(int t) {
        int pos = upper_bound(tt.begin(), tt.end(), t) - tt.begin() - 1;
        return tp[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */