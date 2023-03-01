#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48;ch = getchar(); }
    return x * f;
}
int main() {
    // ios_base::sync_with_stdio(false);
    int n, m;
    n = read();
    m = read();
    // cin >> n >> m;
    vi a(n);
    vi log2n = vi(n + 1);
    log2n[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2n[i] = log2n[i / 2] + 1;
    }
    rep(i, 0, n) {
        // cin >> a[i];
        a[i] = read();
    }
    vvi f;
    f = vvi(n, vi(log2n[n] + 1, -1));

    for (int i = 0; i < n; i++) {
        f[i][0] = a[i];
    }

    // int log2n = log2(n);
    for (int j = 1; j <= log2n[n]; j++) {
        int powj = pow(2, j - 1);
        for (int i = 0; i + powj < n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + powj][j - 1]);
        }
    }

    rep(i, 0, m) {
        int l, r;
        // cin >> l >> r;
        l = read();
        r = read();
        l--;
        r--;
        int s = log2(r - l + 1);
        int ans = max(f[l][s], f[r - pow(2, s) + 1][s]);
        // cout << ans << endl;
        printf("%d\n", ans);
    }
    return 0;
}
