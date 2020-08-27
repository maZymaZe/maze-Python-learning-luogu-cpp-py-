class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,std::greater<string> > > mp;
    vector<string> v;
    void dfs(const string& cur){
        while(mp.count(cur)&&mp[cur].size()){
            string t=mp[cur].top();
            mp[cur].pop();
            dfs(move(t));
        }
        v.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &i:tickets){
            mp[i[0]].push(i[1]);
        }
        dfs("JFK");
        reverse(v.begin(),v.end());
        return v;
    }
};