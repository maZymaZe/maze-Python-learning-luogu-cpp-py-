#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
struct pr{
    int pos;
    char  c;
};
using namespace std;
int main(){
    bool m[120]={0},u[120]={0};
    char w,ck[300],ls[300];
    
    ck[']']='[';

    ck[')']='(';
    vector<char> khs;
    stack<pr> sk;
    pr tmp;
    scanf("%s",ls);
    int p=-1,en=strlen(ls);
    while(p<en-1){
        p++;
        khs.push_back(ls[p]);
        if(ls[p]=='['||ls[p]=='('){
            tmp.c=ls[p];
            tmp.pos=p;
            sk.push(tmp);
        }
        else{
            if(!sk.empty())
            if(sk.top().c==ck[ls[p]]){
                u[sk.top().pos]=u[p]=1;
                sk.pop();
            }
        }
    }
    for(int i=0;i<khs.size();i++){
        if(u[i])putchar(khs[i]);
        else{
            if(khs[i]=='('||khs[i]==')')printf("()");
             if(khs[i]=='['||khs[i]==']')printf("[]");
        }
    }
    return 0;
}