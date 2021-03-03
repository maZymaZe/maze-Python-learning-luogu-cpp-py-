#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
struct Matrix{
    ll num[6][6];
    Matrix(){memset(num,0,sizeof(num));}
    ll* operator[](const ll& x){return num[x];}
    const ll* operator[](const ll& x)const{return num[x];}
}mat,mat2,x,x2;
const ll NMAX=2e5+10,MOD=1e9 + 7;
ll f1,f2,f3,c,res;
ll n;
ll qpow(ll a, ll b){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a% MOD;
        a=a*a% MOD;
        b>>=1;
    }
    return ret;
}
Matrix operator*(const Matrix& x, const Matrix&y){
    Matrix res;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            for(int k=1;k<=5;k++)
            (res[i][j]+=x[i][k]*y[k][j]%(MOD-1))%=( MOD-1);
        }
    }
    return res;
}
Matrix qpow(Matrix x,ll y){
    Matrix res;
    for(int i=1;i<=5;i++)res[i][i]=1;
    while(y){
        if(y&1)res=res*x;
        x=x*x;
        y>>=1;
    }
    return res;
}
int main(){
    cin>>n>>f1>>f2>>f3>>c,res=1;
    mat[1][1]=mat[2][1]=mat[3][1]=mat[1][2]=mat[2][3]=mat[4][4]=mat[5][4]=1;
    mat[5][5]=x[1][5]=mat2[1][1]=1,mat[4][1]=2,mat[5][1]=MOD-5,x[1][4]=3;
    mat2[2][1]=mat2[3][1]=mat2[1][2]=mat2[2][3]=x2[1][3]=1;
    res=qpow(c,(x*qpow(mat,n-3))[1][1]);
    res=res*qpow(f1,(x2*qpow(mat2,n-3))[1][1])%MOD;x2[1][3]=0,x2[1][2]=1;
    res=res*qpow(f2,(x2*qpow(mat2,n-3))[1][1])%MOD;x2[1][2]=0,x2[1][1]=1;
    res=res*qpow(f3,(x2*qpow(mat2,n-3))[1][1])%MOD;
    cout<<res<<endl;
    return 0;
}