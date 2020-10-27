struct EDGE{
    int v,nx;
};
class Solution {
public:
    int v[2003]={0},h[2003]= {0},p=0;
    EDGE e[20004];
    bool flag;
    void add(int a,int b){
        e[++p]={b,h[a]},h[a]=p;
    }
    void dfs(int t,int c){
        v[t]=c;
        for(int i=h[t]; i; i = e[i].nx){
            if(!v[e[i].v]){
                dfs(e[i].v,c^3);
            }else if(v[e[i].v]==c){
                flag=false; break;
            }
            if(!flag)break;
        }
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int l=dislikes.size();
        flag=true;
        for(int  i=0; i<l;i++){
            add(dislikes[i][0],dislikes[i][1]);
            add(dislikes[i][1],dislikes[i][0]);
        }
        for(int i=1;i<=N;i++){
            if(!v[i]){
                dfs(i,1);
            }
            if(!flag)break;
        }
        return flag;
    }
};