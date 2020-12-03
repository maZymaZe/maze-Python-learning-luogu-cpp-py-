class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        
        int n=deck.size();vector<int> ans(n),r;
        deque<int> t(n);
        for(int i=0; i<n; i++)t[i]=i;
        while(!t.empty()){
            r.push_back(t.front());
            t.pop_front();
            if(!t.empty()){
                t.push_back(t.front());
                t.pop_front();
            }
        }
        for(int i = 0;i<n;i++)
        ans[r[i]]=deck[i];
        return ans;
    }
};