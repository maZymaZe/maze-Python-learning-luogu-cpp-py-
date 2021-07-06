class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        set<string> s;
        map<int,unordered_map<string,int>> db;
        int l=orders.size();
        for(int i=0; i<l;i++){
            s.insert(orders[i][2]);
            int d=stoi(orders[i][1]);
            (db[d])[orders[i][2]]++;
        }
        int n=db.size(),m=s.size();
        ans.resize(n+1);
        ans[0].resize(m+1);
        ans[0][0]="Table";
        vector<string> v(s.begin(),s.end());
        for(int i=1;i<=m;i++){
            ans[0][i]=v[i-1];
        }
        auto it=db.begin();
        for(int i=1;i<=n;i++){
            int h=it->first;
            ans[i].resize(m+1);
            ans[i][0]=to_string(h);
            for(int j=1;j<=m;j++){
                ans[i][j]=to_string((it->second)[v[j-1]]);
            }
            ++it;
        }
        return ans;
    }
};