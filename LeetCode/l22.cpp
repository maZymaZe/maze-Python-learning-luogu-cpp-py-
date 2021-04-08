class Solution {
public:
    vector<string> ans;
    int lim;
    string str;
    void dfs(int pos,int s){
        if(pos==lim){
            if(s==0)
            ans.push_back(str);
            return;
        }
        if(s){
            str.push_back(')');
            dfs(pos+1,s-1);
            str.pop_back();
        }
        str.push_back('(');
        dfs(pos+1,s+1);
        str.pop_back();


    }
    vector<string> generateParenthesis(int n) {
        lim=2*n;
        dfs(0,0);
        return ans;
    }
};