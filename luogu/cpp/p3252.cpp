#include<cstdio>
int fa[100003][18],len[100003][18];
int n,m,s,x,y,ans;
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)scanf("%d",&len[i][0]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&x, &y);
        fa[y][0]=x;
    }
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
            len[j][i]=len[j][i-1]+len[fa[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=n;i++){
        int p=0,q=i;
        for(int j=17;j>=0;j--){
            if(len[q][j]+p<=s){
                p+=len[q][j];
                q=fa[q][j];
            }
            if(p==s){
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}