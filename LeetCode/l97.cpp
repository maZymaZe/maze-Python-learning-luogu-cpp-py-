int l1,l2,l3;

bool f(string &s1, string &s2, string &s3,int p1,int p2,vector<vector<int> >&dp,vector<vector<int> >&vis){
    if(vis[p1][p2])return dp[p1][p2];
    if(p1==s1.size()&&p2==s2.size())return true;
    if(p1==s1.size()){
        if(s2[p2]==s3[p1+p2])return f(s1,s2,s3,p1,p2+1,dp,vis);
        else return false;
    }
    if(p2==s2.size()){
        if(s1[p1]==s3[p1+p2])return f(s1,s2,s3,p1+1,p2,dp,vis);
        else return false;
    }
    bool b1=false,b2=false;
    if(s1[p1]==s3[p1+p2])b1=f(s1,s2,s3,p1+1,p2,dp,vis);
    if(s2[p2]==s3[p1+p2])b2=f(s1,s2,s3,p1,p2+1,dp,vis);
    vis[p1][p2]=1;
    return dp[p1][p2]=b1||b2;
}
class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {  
        l1=s1.size(),l2=s2.size(),l3=s3.size();
        if(l3!=l1+l2)return false;
        if(l1==0&&l2==0)return s3=="";
        if(l1==0)return s2==s3;
        if(l2==0)return s1==s3;
        vector<vector<int> > dp(l1+2,vector<int>(l2+2,0)),vis(l1+2,vector<int>(l2+2,0));
        return f(s1,s2,s3,0,0,dp,vis);
    }
};