#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
unordered_set<string> se;
string s;
int n;
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        int l=s.size();
        for(int j=0; j<l; j++){
            if(s[j]=='/')se.insert(s.substr(0,j));
        }
        se.insert(s);
        cout<<se.size()-1<<endl;
    }
    return 0;
}