#include <cstdio>
#include <cstring>
const int MAXSIZE = 1e6 + 5;
const int MOD = 19260817;
inline int max(int a, int b) {
    return a > b ? a : b;
}
char q[MAXSIZE];
int C[MAXSIZE];
long long sum[MAXSIZE], ten[MAXSIZE];
int lenA, lenB, lenC, carry = 0, lenQ;
int t, hc;
int pluspos = 0, equalpos = 0;
int hash(int l, int r) {
    if (l == 0)
        return sum[r] % MOD;
    return ((sum[r] - (sum[l - 1] * ten[r - l + 1]) % MOD) + MOD) % MOD;
}
inline bool check() {
    if (pluspos < 1)
        return false;
    if (pluspos > 1 && q[0] == '0')
        return false;
    if (equalpos - pluspos < 1)
        return false;
    if (equalpos - pluspos > 1 && q[pluspos] == '0')
        return false;

    carry = 0;
    lenA = pluspos;
    lenB = equalpos - pluspos;
    int lenC = max(lenA, lenB);
    int lenR = lenQ - equalpos;
    if (lenC > lenR)
        return false;

    if (lenR > lenA && lenR > lenB) {
        if (q[equalpos] != '1')
            return false;
    } else if (lenR == lenA && lenR == lenB) {
        int pre = q[equalpos] - q[0] - q[pluspos] + '0';
        if (pre != 0 && pre != 1)
            return false;
    } else if (lenA == lenR) {
        if (q[equalpos] - q[0] != 0 && q[equalpos] - q[0] != 1)
            return false;
    } else if (lenB == lenR) {
        if (q[equalpos] - q[pluspos] != 0 && q[equalpos] - q[pluspos] != 1)
            return false;
    }

    if ((hash(0, pluspos - 1) + hash(pluspos, equalpos - 1)) % MOD != hc)
        return false;

    for (register int i = 1, j = lenQ - 1; i <= lenC; i++, j--) {
        C[i] = carry;
        if (pluspos - i >= 0)
            C[i] += q[pluspos - i] - '0';
        if (equalpos - i >= pluspos)
            C[i] += q[equalpos - i] - '0';
        carry = C[i] / 10;
        C[i] %= 10;
        if (C[i] != q[j] - '0')
            return false;
    }
    if (carry)
        C[++lenC] = carry;
    if (lenQ - equalpos != lenC)
        return false;
    if (C[lenC] != q[equalpos] - '0')
        return false;

    return true;
}
void output() {
    for (register int i = 0; i < pluspos; i++)
        putchar(q[i]);
    putchar('+');
    for (register int i = pluspos; i < equalpos; i++)
        putchar(q[i]);
    putchar('=');
    for (register int i = equalpos; i < lenQ; i++)
        putchar(q[i]);
}
int main() {
    gets(q);
    lenQ = strlen(q);
    sum[0] = q[0] - '0';
    ten[0] = 1;
    for (register int i = 1; i < lenQ; i++) {
        sum[i] = (sum[i - 1] * 10 + q[i] - '0') % MOD;
        ten[i] = (ten[i - 1] * 10) % MOD;
    }

    int lim = lenQ / 2;
    for (register int i = lenQ / 3; i <= lim; i++) {
        equalpos = lenQ - i;
        if (lenQ - equalpos < 1)
            continue;
        if (lenQ - equalpos > 1 && q[equalpos] == '0')
            continue;

        hc = hash(equalpos, lenQ - 1);

        pluspos = i;
        if (check()) {
            output();
            return 0;
        }

        pluspos = i - 1;
        if (check()) {
            output();
            return 0;
        }

        pluspos = equalpos - i;
        if (check()) {
            output();
            return 0;
        }

        pluspos = equalpos - i + 1;
        if (check()) {
            output();
            return 0;
        }
    }
    return 0;
}