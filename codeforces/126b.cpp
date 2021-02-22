#include<cstring>
#include<cstdio>
using namespace std;
const int NMAX=1e6+10;
char a[NMAX];
int nxt[NMAX],n,m=0;
void calnxt(){
    nxt[1]=0;
    int j=0;
    for(int i=2;i<=n;i++){
        while(j&&a[i]!=a[j+1])j=nxt[j];
        if(a[i]==a[j+1])j++;
        nxt[i]=j;
        if(i!=n&&nxt[i]>m)m=nxt[i];
    }
}
int main() {
    scanf("%s",a+1);
    n=strlen(a+1);
    calnxt();
    int x=nxt[n];
    if(x==0){
        printf("Just a legend\n");
        return 0;
    }
    while(x>m)x=nxt[x];
    if(x==0){
        printf("Just a legend\n");
        return 0;
    }
    for(int i=2;i<n;i++){
        if(x==nxt[i]){
            for(int j=i-nxt[i]+1;j<=i;j++){
                printf("%c",a[j]);
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}