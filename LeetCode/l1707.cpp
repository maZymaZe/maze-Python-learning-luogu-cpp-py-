class Trie {
   public:
    const int L = 30;
    Trie* children[2] = {};
    void insert(int val) {
        Trie* node = this;
        for (int i = L - 1; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr)
                node->children[bit] = new Trie();
            node = node->children[bit];
        }
    }
    int getMaxXor(int val) {
        int ans=0;
        Trie* node = this;
        for (int i = L - 1; i >= 0; i--){
            int bit = (val >> i) & 1;
            if(node->children[bit^1]!= nullptr){
                ans|=1<<i;
                bit^=1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};
class Solution {
   public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int nq = queries.size();
        for (int i = 0; i < nq; i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });
        vector<int> ans(nq);
        Trie* t=new Trie();
        int idx=0,n=nums.size();
        for(auto& q : queries){
            int x=q[0],m=q[1],qid=q[2];
            while(idx<n&&nums[idx]<=m){
                t->insert(nums[idx]);
                ++idx;
            }
            if(idx==0)ans[qid]=-1;
            else ans[qid]=t->getMaxXor(x);
        }
        return ans;
    }
};