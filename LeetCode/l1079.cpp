int p=0,cnt[10]={0},v[300]={0},ans=0,l,u[20]={0};
class Solution {
public:
    void dfs(int now){ 
       ans++;
        if(now<l){
            for(int i=1;i<=p;i++){
                    if(u[i]<cnt[i]){
                        u[i]++;
                        dfs(now+1);
                        u[i]--;
                    }
                }
        }
    }
    int numTilePossibilities(string tiles) {
        ans=0;p=0;
        memset(v,0,sizeof(v));
        memset(u,0,sizeof(u));
        memset(cnt,0,sizeof(cnt));
        l=tiles.size();
        for(int i=0;i<l;i++){
            if(v[(int)tiles[i]]==0){
                p++;cnt[p]=1;
                v[(int)tiles[i]]=1;
                for(int j=i+1;j<l;j++){
                    if(tiles[i]==tiles[j])cnt[p]++;
                }
            }
        }
       
        dfs(0);
        return ans-1;
    }
};