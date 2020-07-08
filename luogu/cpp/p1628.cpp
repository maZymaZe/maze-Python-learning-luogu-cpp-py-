#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> a,b;
    string t;
    for(int i=0; i<n;i++){
        cin>>t;
        a.push_back(t);
    }
    cin>>t;
    int l=t.size();
    for(int i=0; i<n;i++){
        if(a[i].substr(0,l)==t){
            b.push_back(a[i]);
        }
    }
    sort(b.begin(), b.end());
    for(int i=0; i<b.size();i++){
        cout<<b[i]<<endl;
    }
    return 0;
}