#include <cstdio>
#include <map>
#include <set>
#include<iostream>
#include<string>
using namespace std;
int x, y, n, t1, t2;
char c;
map<int, int> xl, yl;
set<int> xp, yp;
string s;
int main() {
    scanf("%d%d%d", &x, &y, &n);
    xl.insert({x, 1}), yl.insert({y, 1}), xp.insert(0), xp.insert(x),
        yp.insert(0), yp.insert(y);
    for (int i = 0; i < n; i++) {
        cin>>s;
        scanf("%d",&t1);
        if(s[0]=='H'){
            auto t=yp.lower_bound(t1);
            auto tt=--t;
            ++t;
            t2=*t-*tt;
            yl[t2]--;
            if(yl[t2]==0)yl.erase(t2);
            yl[*t-t1]++;
            yl[t1-*tt]++;
            yp.insert(t1);
        }else{
            auto t=xp.lower_bound(t1);
            auto tt=--t;
            ++t;
            t2=*t-*tt;
            xl[t2]--;
            if(xl[t2]==0)xl.erase(t2);
            xl[*t-t1]++;
            xl[t1-*tt]++;
            xp.insert(t1);
        }
        auto t=--yl.end();
        auto tt=--xl.end();
        printf("%lld\n",(long long)(t->first)*(tt->first));
    }
    return 0;
}