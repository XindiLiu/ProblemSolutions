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
struct g {
    int t, f, h;
};
bool operator < (const g& a, const g& b) { return a.t < b.t; }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int d, n;
    cin >> d >> n;
    vector<g> it(n + 1);
    vi t(n + 1, 0);
    vi f(n + 1, 0);
    vi h(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> it[i].t >> it[i].f >> it[i].h;
    }
    sort(it.begin(), it.end(), less<g>());
    for (int i = 1; i <= n; ++i) {
        t[i] = it[i].t;
        f[i] = it[i].f;
        h[i] = it[i].h;
    }
    int m = d + *max_element(h.begin(), h.end());
    vvi dp(n + 1, vi(m + 1, 0));
    dp[0][0] = 10;
    int ans;
    for (int i = 1; i <= n; ++i) {
        bool alive = false;
        for (int j = 0; j <= m; ++j) {
            if (dp[i - 1][j] >= t[i]) { // survive until garbage i comes.
                alive = true;
                dp[i][j] = dp[i - 1][j] + f[i];
            }
            if (j >= h[i] && dp[i - 1][j - h[i]] >= t[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]]);
            }

            if (j >= d && dp[i][j] > 0) {
                ans = t[i];
                goto out;
            }
        }
        if (!alive) {
            ans = dp[i - 1][0];
            goto out;
        }
    }
    ans = dp[n][0];

out:
    cout << ans;
    return 0;
}
