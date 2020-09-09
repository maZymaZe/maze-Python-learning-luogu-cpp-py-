#include<cstdio>
const int MAXSIZE =2e6+ 10;
int n,op,data[MAXSIZE],t;
inline int ls(int x) {return x << 1;}
inline int rs(int x) {return (x << 1) | 1;}
inline int dad(int x) {return x/2;}
void swap(int &a,int &b){int tmp=a;a=b;b=tmp;}
class my_priority_queue{
    private:
        int tot;
        void modif(int x){
            if(x==1)return;
            if(data[x]<data[dad(x)])swap(data[dad(x)],data[x]);
            modif(dad(x));
        }
        void rep(int x){
            if(rs(x)>tot){
                if(ls(x)>tot)return;
                if(data[x]>data[ls(x)]){
                    swap(data[x],data[ls(x)]);
                    rep(ls(x));
                }
            }
            int tar=data[ls(x)]<data[rs(x)]?ls(x):rs(x);
            if(data[x]>data[tar])swap(data[x],data[tar]),rep(tar);
        }
    public:
        my_priority_queue():tot(0){}
        int size(){return tot;}
        void push(int x){
            data[++tot]=x;
            modif(tot);
        }
        int top(){if(tot)return data[1];return -1;}
        void pop(){data[1]=data[tot--];rep(1);}
};
int main(){
    my_priority_queue q;
    scanf("%d",&n);
    for(int i=0;i<n; i++){
        scanf("%d",&op);
        if(op == 1){
            scanf("%d",&t);
            q.push(t);
        }
        else if(op == 2){
            printf("%d\n",q.top());
        }
        else q.pop();
    }
    return 0;
}