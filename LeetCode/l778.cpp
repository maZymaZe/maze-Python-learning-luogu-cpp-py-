class Solution {
public:
    int f[2501],x[2501],y[2501],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int ff(int x) {return f[x] == x ? x : f[x] = ff(f[x]);}
    int swimInWater(vector<vector<int>>& grid) {
        int l=grid.size();
        if(l==1)return 0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                int p=i*l+j;
                f[p]=p;
                x[grid[i][j]]=i;
                y[grid[i][j]]=j;
            }
        }
        int tar=l*l-1;
        for(int i=0;i<=tar;i++){
            int tx=x[i],ty=y[i];
            for(int j=0;j<4;j++){
                int nx=tx+dx[j],ny=ty+dy[j];
                if(nx>=0&&ny>=0&&nx<l&&ny<l){
                    if(grid[nx][ny]<=i){
                        f[ff(nx*l+ny)]=ff(tx*l+ty);
                    }
                }
            }
            if(ff(0)==ff(tar))return i;
        }
        return -1;
        
    }
};