#include<cstdio>
const int MAXLEN= 1e6+10;
int n,Next[MAXLEN];
char s[MAXLEN];
void getNext(){
    Next[0]=-1;
    for(int i=1;i<n;i++){
        int j=Next[i-1];
        while(j>=0&&s[j+1]!=s[i]){
            j=Next[j];
        }
        if(s[j+1]==s[i])Next[i]=j+1;
        else Next[i]=-1;
    }
}
int main(){
    scanf("%d", &n);
    scanf("%s",s);
    getNext();
    int re=n-Next[n-1]-1;
    printf("%d\n",re);
    return  0;
}