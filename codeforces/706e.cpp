#include<cstdio>
inline void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
const int NODESIZE=1e6+9999;
inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}
int n,m,q,tv,a,b,c,d,h,w;
struct NODE{
    int nx,ny;
    int v;
}node[NODESIZE];
int hx[1003]={0},hy[1003]={0},cnt=0;
int main(){
    n=Read(),m=Read(),q=Read();
    for(int i=0;i<=m;i++){
        node[++cnt]={i+m+2,i+2,0};hy[i]=cnt;
    }
    node[cnt].ny=0;
    hx[0]=1;
    for(int i=1;i<=n;i++){
        if(i<n)node[++cnt]={cnt+m+1,cnt+1,0},hx[i]=cnt;
        else node[++cnt]={0,cnt+1,0},hx[i]=cnt;
        for(int j=1;j<=m;j++){
            tv=Read();
            node[++cnt]={cnt+m+1,cnt+1,tv};
        }
        node[cnt].ny=0;
    }

    for(int i=1;i<=q;i++){
        a=Read(),b=Read(),c=Read(),d=Read(),h=Read(),w=Read();
        int a_hd=hx[a-1],b_hd=hx[c-1];
        for(int j=1;j<b;j++)a_hd=node[a_hd].ny;
        for(int j=1;j<d;j++)b_hd=node[b_hd].ny;

        int p1_a=node[a_hd].ny,p1_b=node[b_hd].ny;
        int p2_a=node[a_hd].nx,p2_b=node[b_hd].nx;
        
        for(int j=1;j<w;j++){
            swap(node[p1_a].nx,node[p1_b].nx);
            p1_a=node[p1_a].ny,p1_b=node[p1_b].ny;
        }
        swap(node[p1_a].nx,node[p1_b].nx);
        p1_a=node[p1_a].nx,p1_b=node[p1_b].nx;


        for(int j=1;j<h;j++){
            swap(node[p2_a].ny,node[p2_b].ny);
            p2_a=node[p2_a].nx,p2_b=node[p2_b].nx;
        }
        swap(node[p2_a].ny,node[p2_b].ny);
        p2_a=node[p2_a].ny,p2_b=node[p2_b].ny;

        for(int j=1;j<=w;j++){
            swap(node[p2_a].nx,node[p2_b].nx);
            p2_a=node[p2_a].ny,p2_b=node[p2_b].ny;
        }

        for(int j=1;j<=h;j++){
            swap(node[p1_a].ny,node[p1_b].ny);
            p1_a=node[p1_a].nx,p1_b=node[p1_b].nx;
        }
    }
    for(int i=1;i<=n;i++){
        int p=hx[i];p=node[p].ny;
        for(int j=1;j<=m;j++){
            printf("%d ",node[p].v);
            p=node[p].ny;
        }
        printf("\n");
    }
    return 0;
} 