class Solution {
public:
    string d;
    vector<string> ans;
    char s[1000]={0};
    vector<vector<char> > tbl={{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},
    {'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
    int l;
    void dfs(int x){
        if(x==l){
            ans.push_back(string(s));
            return;
        }
        for(char &i:tbl[d[x]-'2']){
            s[x]=i;
            dfs(x+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        l=digits.size();
        if(!l)return ans;
        d=digits;
        dfs(0);
        return ans;
    }
};