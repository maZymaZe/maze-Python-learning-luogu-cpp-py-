class Solution {
public:
    int l;
    vector<string> ans;
    void dfs(int x,string& s){
        if(x==l){
            ans.push_back(s);
            return;
        }
        if(s[x]>='a'&&s[x]<='z'){
            dfs(x+1,s);
            s[x]=s[x]-'a'+'A';
            dfs(x+1,s);
        }else if(s[x]>='A'&&s[x]<='Z'){
            dfs(x+1,s);
            s[x]=s[x]+'a'-'A';
            dfs(x+1,s);
        }else dfs(x+1,s);
    }
    vector<string> letterCasePermutation(string S) {
        l=S.size();
        dfs(0,S);
        return ans;
    }
};