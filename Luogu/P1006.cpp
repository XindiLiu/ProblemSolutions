#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx)
using namespace std;
int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    vector<vector<int>> e(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)scanf("%d", &e[i][j]);
    }
    vector<vector<vector<int>>> f(m + n - 2, vector<vector<int>>(m, vector<int>(m, 0)));
    f[0][0][0] = e[0][1] + e[1][0];
    for (int i = 1; i <= m + n - 4; i++) {
        visa(i)
            for (int j2 = (i > n - 2) ? (i - n + 2) : 0; j2 < m - 1 && j2 <= i; j2++) {
                visa(j2)
                    for (int j1 = (i > n - 2) ? (i - n + 2) : 0; j1 < m - 1 && j1 <= j2; j1++) {
                        visa(j1)
                            if (j2 == i && j1 == 0) {
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2 - 1]);
                                visa(f[i - 1][j1][j2 - 1])
                            }
                            else if (j1 == 0) {
                                if (j1 != j2) { f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2 - 1]); visa(f[i - 1][j1][j2 - 1]) }
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2]);
                                visa(f[i - 1][j1][j2])
                            }
                            else if (j2 == i) {
                                if (j1 != j2) { f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2 - 1]); visa(f[i - 1][j1][j2 - 1]) }
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1 - 1][j2 - 1]);
                                visa(f[i - 1][j1 - 1][j2 - 1])
                            }
                            else {
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2]);
                                visa(f[i - 1][j1][j2])
                                    if (j1 != j2) { f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1][j2 - 1]); visa(f[i - 1][j1][j2 - 1]) }
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1 - 1][j2]);
                                f[i][j1][j2] = max(f[i][j1][j2], f[i - 1][j1 - 1][j2 - 1]);
                                visa(f[i - 1][j1 - 1][j2]) visa(f[i - 1][j1 - 1][j2 - 1])
                            }
                        visa(f[i][j1][j2])
                            f[i][j1][j2] += e[j1][1 + i - j1] + e[1 + j2][i - j2];
                        visa(f[i][j1][j2])
                    }
            }
    }
    cout << f[n + m - 4][m - 2][m - 2];
    return 0;
}
/*
3 3
0 3 9
2 8 5
5 7 0
*/