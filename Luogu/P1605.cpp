#include <bits/stdc++.h>
using namespace std;
int n, m, t, s = 0, sx, sy, fx, fy, zx, zy;
vector<vector<int>> zg;
void f(int x, int y);
int main() {
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    zg.assign(n + 2, vector<int>(m + 2, 1));
    for (int i = 0; i < t; ++i) {
        scanf("%d%d", &zx, &zy);
        zg[zx][zy] = 0;
    }
    zg[sx][sy] = 0;
    f(sx, sy);
    printf("%d", s);
    return 0;

}
void f(int x, int y) {
    if (x == fx && y == fy) {
        ++s;
        return;
    }
    if (zg[x][y + 1] && y + 1 <= m) {
        zg[x][y + 1] = 0;
        f(x, y + 1);
        zg[x][y + 1] = 1;
    }
    if (zg[x + 1][y] && x + 1 <= n) {
        zg[x + 1][y] = 0;
        f(x + 1, y);
        zg[x + 1][y] = 1;
    }
    if (zg[x - 1][y] && x - 1 > 0) {
        zg[x - 1][y] = 0;
        f(x - 1, y);
        zg[x - 1][y] = 1;
    }
    if (zg[x][y - 1] && y - 1 > 0) {
        zg[x][y - 1] = 0;
        f(x, y - 1);
        zg[x][y - 1] = 1;
    }
}