#include <cstdio>
#include <cstring>
int st[120], h[120], n, mx = 0, t;
int ffs(int l,int r,int v){
    if(st[l]>=v)return l;
    else{
        int mid=(l+r)/2;
        while(r-l>=1){
            mid=(l+r)/2;
            if(st[mid]<v&&st[mid+1]>=v)return mid+1;
            else if(st[mid]>=v)r=mid;
            else if(st[mid+1]<v)l=mid;
            
            
        }
        return l;
    }
}
int up(int l, int r)
{
    int len = 1,tt;
    memset(st, 0, sizeof(st));
    st[1] = h[l];
    for (int i = l + 1; i <= r; i++)
    {
        if(h[i]>st[len]){
            len++;
            st[len]=h[i];
        }
        else{
            tt=ffs(1,len,h[i]);
            st[tt]=h[i];
        }
    }
    return len;
}
int ffb(int l,int r,int v){
    if(st[l]<=v)return l;
    else{
        int mid=(l+r)/2;
        while(r-l>=1){
            mid=(l+r)/2;
            if(st[mid]>v&&st[mid+1]<=v)return mid+1;
            else if(st[mid]<=v)r=mid;
            else if(st[mid+1]>v)l=mid;
        }
        return l;
    }
}
int dw(int l, int r)
{
    int len = 1,tt;
    memset(st, 0, sizeof(st));
    st[1] = h[l];
    for (int i = l + 1; i <= r; i++)
    {
        if(h[i]<st[len]){
            len++;
            st[len]=h[i];
        }
        else{
            tt=ffb(1,len,h[i]);
            st[tt]=h[i];
        }
    }
    return len;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        t = up(1, i) + dw(i, n) - 1;
        if(t>mx)mx=t;
    }
    printf("%d",n-mx);
    return 0;
}
