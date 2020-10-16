#include <cstdio>
#include <deque>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1e5 + 10;
int n, nums[MAXN], m1, m2, m3, p1, p2, p3, pre = 1;
string words[8] = {"pushStack", "pushQueue", "pushFront", "pushBack",
                   "popStack",  "popQueue",  "popFront",  "popBack"};
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] == 0) {
            if (!p1)
                printf("0\n");
            else if (!p2) {
                for (int j = pre; j < i; j++) {
                    if (j == p1)
                        cout << words[2] << endl;
                }
                cout << "1 " << words[6] << endl;
            } else if (!p3) {
                for (int j = pre; j < i; j++) {
                    if (j == p1)
                        cout << words[2] << endl;
                    else if (j == p2)
                        cout << words[1] << endl;
                }
                cout << "2 " << words[6] << ' ' << words[5] << endl;
            } else {
                for (int j = pre; j < i; j++) {
                    if (j == p1)
                        cout << words[2] << endl;
                    else if (j == p2)
                        cout << words[1] << endl;
                    else if (j == p3)
                        cout << words[0] << endl;
                    else
                        cout << words[3] << endl;
                }
                cout << "3 " << words[6] << ' ' << words[5] << ' ' << words[4]
                     << endl;
            }
            m1 = m2 = m3 = p1 = p2 = p3 = 0;
            pre = i + 1;
        } else {
            if (!p1)
                p1 = i, m1 = nums[i];
            else if (!p2) {
                if (nums[i] > m1)
                    p2 = p1, m2 = m1, p1 = i, m1 = nums[i];
                else
                    p2 = i, m2 = nums[i];
            } else {
                if (nums[i] > m1) {
                    m3 = m2, m2 = m1, m1 = nums[i];
                    p3 = p2, p2 = p1, p1 = i;
                } else if (nums[i] > m2) {
                    m3 = m2, m2 = nums[i];
                    p3 = p2, p2 = i;
                } else if (nums[i] > m3) {
                    p3 = i, m3 = nums[i];
                }
            }
        }
    }
    for (int i = pre; i <= n; i++)
        cout << words[0] << endl;
    return 0;
}