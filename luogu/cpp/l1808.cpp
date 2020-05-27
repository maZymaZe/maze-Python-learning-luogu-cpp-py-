#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, ans = 1;
int main() {
    cin >> n;
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    s=v[0];
    for(int i=1; i<n; i++){
        if(v[i]!=s){
            s=v[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}