#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
int n,m,t,mp[550][550],cnt=0,l[550];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void f(int x,int y){
    mp[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=n&&ny<=l[x]&&mp[nx][ny])f(nx,ny);
    }
}
int main() {
    scanf("%d",&n);
    string s;
     getline(cin,s);
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        l[i]=s.size();
        for(int j=1;j<=l[i];j++)
        {
        	if(s[j-1]>='a' && s[j-1]<='z')
                mp[i][j]=1;	
        }
    }
    m=s.size();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l[i];j++){
            
            if(mp[i][j]==1){
                cnt++;
                f(i,j);
            }
        }
    }
    printf("%d",cnt);
    return 0;
}