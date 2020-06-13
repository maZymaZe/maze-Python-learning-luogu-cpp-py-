#include<cstdio>
int k,a,b;
void solve(int s,int x,int y){
    if(s==1){
        if(x%2==0&&y%2==0)printf("%d %d %d\n",x-1,y-1,4);
        if(x%2==0&&y%2==1)printf("%d %d %d\n",x-1,y+1,3);
        if(x%2==1&&y%2==1)printf("%d %d %d\n",x+1,y+1,1);
        if(x%2==1&&y%2==0)printf("%d %d %d\n",x+1,y-1,2);
    }
    else{
        int t=(1<<(s-1)),tt=(1<<s);
        if(((x-1)%tt+1)>t&&((y-1)%tt+1)<=t){
            int t1=x-((x-1)%t+1),t2=y-((y-1)%t+1)+t;
            solve(s-1,x,y);
            printf("%d %d %d\n",t1,t2+1,3);
            solve(s-1,t1,t2);
            solve(s-1,t1+1,t2+1);
            solve(s-1,t1,t2+1);
        }
        if(((x-1)%tt+1)<=t&&((y-1)%tt+1)<=t){
            int t1=x-((x-1)%t+1)+t,t2=y-((y-1)%t+1)+t;
            solve(s-1,x,y);
            printf("%d %d %d\n",t1+1,t2+1,1);
            solve(s-1,t1+1,t2+1);
            solve(s-1,t1+1,t2);
            solve(s-1,t1,t2+1);
        }
        if(((x-1)%tt+1)>t&&((y-1)%tt+1)>t){
            int t1=x-((x-1)%t+1),t2=y-((y-1)%t+1);
            solve(s-1,x,y);
            printf("%d %d %d\n",t1,t2,4);
            solve(s-1,t1+1,t2);
            solve(s-1,t1,t2);
            solve(s-1,t1,t2+1);
        }
        if(((x-1)%tt+1)<=t&&((y-1)%tt+1)>t){
            int t1=x-((x-1)%t+1)+t,t2=y-((y-1)%t+1);
            solve(s-1,x,y);
            printf("%d %d %d\n",t1+1,t2,2);
            solve(s-1,t1,t2);
            solve(s-1,t1+1,t2+1);
            solve(s-1,t1+1,t2);
        }
    }
}

int main(){
    scanf("%d%d%d",&k,&a,&b);
    solve(k,a,b);
    return 0;
}