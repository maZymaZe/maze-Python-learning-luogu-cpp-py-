#include<cstdio>
int mx(int a,int b){
    if(a>b)return a;
    else return b;
}
int d[6][6]=
{
    {0,0,0,0,0,0},
    {0,5,-1,-2,-1,-3},
    {0,-1,5,-3,-2,-4},
    {0,-2,-3,5,-2,-2},
    {0,-1,-2,-2,5,-1},
    {0,-3,-4,-2,-1,0}
};
int main(){
    int f[220][220]={0};
    int l1,l2,s1[120],s2[120];
    char t1[120],t2[120];
    scanf("%d%s%d%s",&l1,t1,&l2,t2);
    for(int i=0;i<l1;i++){
        if(t1[i]=='A')s1[i+1]=1;
        if(t1[i]=='C')s1[i+1]=2;
        if(t1[i]=='G')s1[i+1]=3;
        if(t1[i]=='T')s1[i+1]=4;
    }
    for(int i=0;i<l2;i++){
        if(t2[i]=='A')s2[i+1]=1;
        if(t2[i]=='C')s2[i+1]=2;
        if(t2[i]=='G')s2[i+1]=3;
        if(t2[i]=='T')s2[i+1]=4;
    }
    for(int i=1;i<=l1;i++){
        f[i][0]=f[i-1][0]+d[s1[i]][5];
    }
    for(int i=1;i<=l2;i++){
        f[0][i]=f[0][i-1]+d[s2[i]][5];
    }
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            f[i][j]=mx(f[i-1][j-1]+d[s1[i]][s2[j]],
            mx(f[i-1][j]+d[5][s1[i]],f[i][j-1]+d[s2[j]][5]));
        }
    }
    printf("%d",f[l1][l2]);
    return 0;
}