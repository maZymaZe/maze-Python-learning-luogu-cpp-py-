class Solution {
public:
    int k,MOD;
    vector<int>* p;
    Solution(int N, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        k=blacklist.size();
        MOD=N-k;
        p=&blacklist;
        for(int i=0;i<k;i++)blacklist[i]-=i;
    }
    
    int pick() {
        int g=rand()%MOD;
        g+=upper_bound(p->begin(), p->end(),g)-(p->begin());
        return g;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */