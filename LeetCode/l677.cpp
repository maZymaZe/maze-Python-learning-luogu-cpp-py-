class MapSum {
public:
    /** Initialize your data structure here. */
    vector<vector<int>> trie;
    vector<int> v;
    int tot;
    MapSum() {
        v.push_back(0);
        trie.resize(1);
        trie[0] .resize(26);
    }
    
    void insert(string key, int val) {
        int l=key.size();
        int p=0;
        for(int i=0; i<l; i++){
            if(trie[p][key[i]-'a'])p=trie[p][key[i]-'a'];
            else{
                int newnode=trie.size();
                trie.push_back(vector<int>());
                trie[newnode].resize(26);
                trie[p][key[i]-'a']=newnode;
                p=newnode;
                v.push_back(0);
            }
        }
        v[p]=val;
    }
    void dfs(int x){
        tot+=v[x];
        for(int i=0;i<26;i++){
            if(trie[x][i])dfs(trie[x][i]);
        }
    }
    int sum(string prefix) {
        int l=prefix.size();
        int p=0;
        for(int i=0; i<l; i++){
            if(trie[p][prefix[i]-'a'])p=trie[p][prefix[i]-'a'];
            else{
               return 0;
            }
        }
        tot=0;
        dfs(p);
        return tot;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */