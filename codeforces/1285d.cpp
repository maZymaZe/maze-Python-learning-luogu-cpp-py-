#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
vector<int> a;
int cal(vector<int>&v,int pos){
    if(pos<0)return 0;
    vector<int> p0,p1;
    for(int i:v){
        if(i&(1<<pos)){
            p1.push_back(i);
        }else{
            p0.push_back(i);
        }
    }
    if(p0.empty()){
        return cal(p1,pos-1);
    }else if(p1.empty()){
        return cal(p0,pos-1);
    }
    return (1<<pos)+min(cal(p1,pos-1),cal(p0,pos-1));
}
int main(){
    scanf("%d",&n);
    a.resize(n);
    for(int i=0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("%d",cal(a,30));
    return 0;
}