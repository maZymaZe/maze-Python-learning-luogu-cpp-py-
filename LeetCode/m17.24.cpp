class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int tmp[203]={0},sm[203][203]={0};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sm[i][j]=sm[i-1][j]+matrix[i-1][j-1];
            }
        }
        int r1,c1,r2,c2,ma=INT_MIN,tma=INT_MIN,tl,tt,tml,tmr;

        for(int u=1;u<=n;u++){
            for(int d=u;d<=n;d++){
                for(int i=1;i<=m;i++){
                    tmp[i]=sm[d][i]-sm[u-1][i];
                }
                tma=tmp[1];tt=0;tl=1;tml=1,tmr=1;
                for(int i=1;i<=m;i++){
                    if(tmp[i]>=0){
                        if(tt<0)tt=tmp[i],tl=i;
                        else tt+=tmp[i];

                        if(tt>tma)tma=tt,tml=tl,tmr=i;
                    }
                    else{
                        if(tmp[i]>tma){
                            tt=tma=tmp[i];tml=i,tmr=i;
                        }else{
                            tt+=tmp[i];
                        }
                    }
                }
                if(tma>ma){
                    ma=tma;r1=u-1,c1=tml-1,r2=d-1,c2=tmr-1;
                }
            }
        }
        return vector<int>{r1,c1,r2,c2};
    }
};