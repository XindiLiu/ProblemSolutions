#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vvi f(n, vi(n, 0));
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        f[i][i] = a[i];
        ans = max(ans, f[i][i]);
    }

    for (int d = 2; d <= n; ++d) {
        for (int i = 0; i < n; ++i) {
            int j = (i + d) % n;
            for (int k1 = 1; k1 < d; ++k1) {
                int k = (i + k1) % n;
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
                ans = max(ans, f[i][j]);
            }
        }
    }
    cout << ans;
    return 0;
}