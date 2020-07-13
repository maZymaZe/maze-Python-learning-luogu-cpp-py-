#include <cstdio>
#include <cstring>
const int TrieSize = 1000006, LetterSize = 26;
int n, m, tt;
char ss[60];
struct trie {
    int Next[TrieSize][LetterSize], Cnt = 0;
    bool Exist[TrieSize], used[TrieSize];
    void TrieInsert(char* s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!Next[p][c])
                Next[p][c] = ++Cnt;
            p = Next[p][c];
        }
        Exist[p] = true;
    }
    int TrieFind(char* s, int len) {
        int p = 0;
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            if (!Next[p][c])
                return false;
            p = Next[p][c];
        }
        if (!Exist[p])
            return 0;
        if (used[p] == true)
            return 2;
        used[p] = true;
        return 1;
    }
} t;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ss);
        t.TrieInsert(ss, strlen(ss));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%s", ss);
        tt = t.TrieFind(ss, strlen(ss));
        if (tt == 0)
            printf("WRONG\n");
        else if (tt == 1)
            printf("OK\n");
        else
            printf("REPEAT\n");
    }
    return 0;
}