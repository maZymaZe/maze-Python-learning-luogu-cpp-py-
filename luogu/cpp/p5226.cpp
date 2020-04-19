#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int n, t, m;
unordered_map<string, int> mp;
int main() {
    scanf("%d",&n);
    string s;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (t == 1) {
            cin >> s >> m;
            mp[s] = m;
            printf("OK\n");
        } else if (t == 2) {
            cin >> s;
            if (mp.find(s) != mp.end())
                printf("%d\n", mp[s]);
            else
                printf("Not found\n");
        } else if (t == 3) {
            cin >> s;
            if (mp.find(s) != mp.end())
                mp.erase(s), printf("Deleted successfully\n");
            else
                printf("Not found\n");
        } else if (t == 4) {
            printf("%d\n", mp.size());
        }
    }
    return 0;
}