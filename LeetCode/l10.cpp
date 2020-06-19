class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        auto mch=[&](int i,int j){
            if(i==0)return false;
            if(p[j-1]=='.')return true;
            return p[j-1]==s[i-1];
        };
        vector<vector<int>> f(m+1,vector<int>(n+1));
        f[0][0]=1;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1]=='*'){
                    f[i][j]|=f[i][j-2];
                    if(mch(i,j-1)){
                        f[i][j]|=f[i-1][j];//负数下标出错可能
                    }
                }
                else{
                    if(mch(i,j)){
                        f[i][j]|=f[i-1][j-1];//负数下标出错可能
                    }
                }
            }
        }
        return f[m][n];
    }
};