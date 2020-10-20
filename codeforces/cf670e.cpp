#include <cstdio>
const int DATASIZE = 5e5+5;
int stk[DATASIZE] = {0}, partner[DATASIZE] = {0}, p = 0, n = 0, m = 0, top = 0,
    deleted[DATASIZE] = {0};
int lb, rb;
char ls[DATASIZE] = {0}, op[DATASIZE] = {0};
int main() {
    scanf("%d%d%d", &n, &m, &p);

    scanf("%s", ls);
    scanf("%s", op);
    p--;
    for (int i = 0; i < n; i++) {
        if (ls[i] == '(')stk[++top] = i;
        else partner[i] = stk[top], partner[stk[top]] = i, top--;
    }
    lb = 0, rb = n - 1;
    for (int i = 0; i < m; i++) {
        if (op[i] == 'L') {
            p--;
            while (p >= lb && deleted[p]) {
                if (ls[p] == '(')p--;
                else p = partner[p], p--;
            }
            if (p < lb) p = lb;
        } else if (op[i] == 'R') {
            p++;
            while (p <= rb && deleted[p]) {
                if (ls[p] == '(')p = partner[p], p++;
                else p++;
            }
            if (p > rb) p = rb;
        } else {
            deleted[p] = 1;
            deleted[partner[p]] = 1;
            int a = p;
            if (p > partner[p])a = partner[p];
            while(a-1>lb&&ls[a-1]==')'&&deleted[a-1]){
                a=partner[a-1];
            }
            int b = partner[p];
            if (p > partner[p]) b = p;
            while(b+1<rb&&ls[b+1]=='('&&deleted[b+1]){
                b=partner[b+1];
            }
            partner[a]=b;partner[b]=a;

            if (a == lb) {
                a = b + 1;
                while (a <= rb && deleted[a]) {
                    if (ls[a] == '(') a = partner[a], a++;
                    else a++;
                }
                p = a, lb = a;
            } else if (b == rb) {
                b = a - 1;
                while (b >= lb && deleted[b]) {
                    if (ls[b] == '(') b--;
                    else b = partner[b], b--;
                }
                p = b, rb = b;
            } else {
                p = b + 1;
                while (p <= rb && deleted[p]) {
                    if (ls[p] == '(') p = partner[p], p++;
                    else p++;
                }
            }
        }

    }
    int k=lb;
    while(k<=rb){
        if(deleted[k]){
            while(k<=rb && deleted[k]){
                k=partner[k]+1;
            }
        }
        else{
            printf("%c",ls[k]);
            k++;
        }
    }
    return 0;
}