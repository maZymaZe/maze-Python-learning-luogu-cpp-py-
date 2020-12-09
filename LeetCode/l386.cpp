class Solution {
public:
    int N;
    vector<int> ans;
    void dfs(int x){
        if(x>N)return;
        ans.push_back(x);
        for(int i=0;i<10;i++)dfs(10*x+i);
    }
    vector<int> lexicalOrder(int n) {
        N=n;
        for(int i=1;i<10;i++)dfs(i);
        return ans;
    }
};