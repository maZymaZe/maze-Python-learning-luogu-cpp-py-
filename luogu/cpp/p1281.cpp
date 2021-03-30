#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[504],l,r,s=0,ansl[504],ansr[504];
bool ck(int p){
    int cnt=1,pre=0;
    for(int i=1;i<=n;i++){
        if(pre&&pre+a[i]>p){
            pre=0;
            cnt++;
        }
        if(pre==0&&pre+a[i]>p){
            return false;
        }
        pre+=a[i];
    }
    return cnt<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    l=1,r=s;
    while(l<r){
        int mid=l+(r-l)/2;
        if(ck(mid))r=mid;
        else l=mid+1;
    }
    int q=n,pq=n,nc=0,cl=k;
    for(int i=n;i>0;i--){
        if(nc+a[i]>r){
            ansl[cl]=i+1, 
            ansr[cl]= pq;
            pq=i;
            cl--;
            nc=a[i];
        }
        else nc+=a[i];
    }
    ansl[cl]=1;
    ansr[cl]=pq;
    for(int i=1;i<=k;i++){
        printf("%d %d\n",ansl[i],ansr[i]);
    }
    return 0;


    
}
