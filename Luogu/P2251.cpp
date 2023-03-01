#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vi items(n);
    rep(i, 0, n) {
        cin >> items[i];
    }
    vi log2n = vi(n + 1);
    log2n[1] = 0;
    rep(i, 2, n + 1) {
        log2n[i] = log2n[i / 2] + 1;
    }
    vvi st = vvi(n, vi(log2n[n] + 1, -1));
    for (int i = 0; i < n; i++) {
        st[i][0] = items[i];
    }
    for (int j = 1; j <= log2n[n]; j++) {
        for (int i = 0; i + pow(2, j - 1) < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + pow(2, j - 1)][j - 1]);
        }
    }

    for (int i = 0; i + m <= n; i++) {
        int s = log2n[m + 1];
        int ans = min(st[i][s], st[i + m - 1 - pow(2, s) + 1][s]);
        cout << ans << endl;
    }






    return 0;
}
