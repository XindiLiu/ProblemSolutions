#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef __uint128_t ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vll pow2(m + 1);
    pow2[0] = 1;
    for (int i = 1; i <= m; ++i) {
        pow2[i] = pow2[i - 1] << 1;
    }
    ll ans = 0;
    for (int r = 0; r < n; ++r) {
        // ll ansrow = 0;
        vector<ll> f(m);
        for (int i = 0; i < m; ++i) {
            f[i] = (ll)a[r][i] * pow2[m];
        }
        vector<ll> fn(m, 0);
        for (int l = 2; l <= m; ++l) {
            for (int i = 0; i + l - 1 < m; ++i) {
                int j = i + l - 1;
                fn[i] = max((ll)a[r][i] * pow2[m - l + 1] + f[i + 1], (ll)a[r][j] * pow2[m - l + 1] + f[i]);
            }
            f = fn;
        }
        ans += f[0];
    }

    long long ans2 = ans % (ll)1e19;
    long long ans1 = (ans - (ll)ans2) / (ll)1e19;
    if (ans1) {
        cout << ans1;
    }
    cout << ans2;
    return 0;
}