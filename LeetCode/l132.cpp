class Solution {
public:
    int mp[2003],len;
    bool ok(string &s,int l,int r){
        while(l<r){
            if(s[l]!=s[r])return false;
            l++,r--;
        }
        return true;
    }
    void dfs(string &s,int x){
        if(mp[x]!=0x3f3f3f3f)return;
        for(int i=x;i<len;i++){
            if(ok(s,x,i)){
                if(i==len-1){mp[x]=0;continue;}
                dfs(s,i+1);
                mp[x]=min(mp[x],mp[i+1]+1);
            }
        }
    }
    int minCut(string s) {
        memset(mp, 0x3f,sizeof(mp));
        len=s.size();
        if(ok(s,0,len-1))return 0;
        mp[len-1]=0;mp[len]=0;
        dfs(s,0);
        return mp[0];
    }
};