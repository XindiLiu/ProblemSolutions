#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
const int inf = -1000000000;
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int mid = n / 2;
    vector<vector<int>> b(m, vector<int>(n));
    vector<vector<int>> f(m, vector<int>(n, inf));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)scanf("%d", &b[i][j]);
    }
    f[m - 1][mid] = b[m - 1][mid];
    f[m - 1][mid - 1] = b[m - 1][mid - 1];
    f[m - 1][mid + 1] = b[m - 1][mid + 1];
    for (int i = m - 2; i >= 0; i--) {
        f[i][0] = max(f[i + 1][0], f[i + 1][1]) + b[i][0];
        f[i][n - 1] = max(f[i + 1][n - 1], f[i + 1][n - 2]) + b[i][n - 1];
        for (int j = 1; j < n - 1; j++) {
            f[i][j] = max(f[i + 1][j - 1], f[i + 1][j]);
            f[i][j] = max(f[i][j], f[i + 1][j + 1]);
            f[i][j] += b[i][j];
        }
    }
    int s = 0;
    for (int i = 0; i < n; i++)s = max(s, f[0][i]);
    printf("%d", s);
    return 0;
}