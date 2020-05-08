int pd[5]={0},n,m,ans; 
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
class Solution {
public:
    int ck(vector<vector<int>> t){
        int d=0;
        for(int i=0;i<m;i++){
            if(pd[i])cg(0,i,t),d++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(t[i-1][j])cg(i,j,t),d++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(t[i][j])return -1;
            }
        }
        return d;
    }
    void cg(int x,int y,vector<vector<int>>& t){
        t[x][y]^=1;
       
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<n&&y+dy[i]>=0&&y+dy[i]<m){
                t[x+dx[i]][y+dy[i]]^=1;
            }
        }
    }
    int minFlips(vector<vector<int>>& mat) {
        memset(pd,0,sizeof(pd));
        n=mat.size(),m=mat[0].size();
        int p=pow(2,m);
        for(int i=1;i<=p;i++){
            ans=ck(mat);
            if(ans!=-1)return ans;
            pd[0]++;
            for(int j=0;j<=3;j++){
                if(pd[j]==2)pd[j]=0,pd[j+1]++;
            }
        }
        return -1;
    }
};