class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    int K,N;
    void dfs(int nb,int cnt,int tot){    
        if(cnt==K&&tot==N){
            ans.emplace_back(tmp);
            return;
        }
        if(tot>N||cnt>K||nb>9)return;
        for(int i=nb;i<10;i++){
            tmp.emplace_back(i);
            dfs(i+1,cnt+1,tot+i);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        K=k,N=n;
        dfs(1,0,0);
        return ans;
    }
};