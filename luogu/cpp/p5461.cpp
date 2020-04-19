#include <cstdio>
int n;
int judge(int x,int y,int z){
    if(z==1){
        if(x==1&&y==1)return 0;
        else return 1;
    }
    else{
        z--;
        if(x<=(1<<z)&&y<=(1<<z))return 0;
        else return judge((x-1)%(1<<z)+1,(y-1)%(1<<z)+1,z);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++){
            printf("%d ",judge(i,j,n));
        }
        printf("\n");
    }
    return 0;
}