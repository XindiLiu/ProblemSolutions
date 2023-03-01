#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define int int
#define f first
#define s second
using namespace std;
int main() {
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    pair<int, int> a[n + 1];
    for (int i = 1; i <= n; i++)scanf("%d%d", &(a[i].f), &(a[i].s));
    int d[n + 1][m + 1][t + 1] = {0};
    for (int i = 0; i <= n; i++)for (int j = 0; j <= m; j++)for (int k = 0; k <= t; k++)d[i][j][k] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= t; k++) {
                if (j >= a[i].f && k >= a[i].s)d[i][j][k] = max(d[i - 1][j][k], d[i - 1][j - a[i].f][k - a[i].s] + 1);
                else d[i][j][k] = d[i - 1][j][k];
            }
        }
    }
    int svar = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= t; j++) {
            svar = max(svar, d[n][i][j]);
        }
    }
    cout << svar;
}