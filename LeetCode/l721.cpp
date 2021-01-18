class Solution {
public:
    unordered_map<string,int> ck;
    vector<int> f;
    int ff(int x) { return f[x] == x ? x : f[x] = ff(f[x]);}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int l=accounts.size();
        f.resize(l);
        for(int i=0; i<l; i++)f[i]=i;
        for(int i=0; i<l;i++){
            int t=accounts[i].size();
            for(int j=1; j<t; j++){
                if(ck.count(accounts[i][j])){
                    int u=ff(i),v=ff(ck[accounts[i][j]]);
                    f[u]=v;
                }else ck.insert({accounts[i][j],ff(i)});
            }
        }
        vector<vector<string>> ans;
        int c=0;
        unordered_map<int,int> mp;
        for(int i=0; i<l; i++){
            if(f[i]==i){
                ans.push_back(vector<string>());
                ans.back().push_back(accounts[i][0]);
                mp.insert({i,c});
                c++;
            }
        }
        for(auto &i:ck){
            ans[mp[ff(i.second)]].push_back(i.first);
        }
        for(int i=0;i<c;i++){
            sort(ans[i].begin()+1,ans[i].begin()+ans[i].size());
        }
        return ans;
    }
};