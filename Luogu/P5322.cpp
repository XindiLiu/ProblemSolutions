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
    int s, n, m;
    cin >> s >> n >> m;
    vvi a(n + 1, vi(s + 1, 0));
    for (int i = 1; i <= s; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[j][i];
            a[j][i] = a[j][i] * 2 + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vvi dp(n + 1, vi(m + 1, 0));
    // set<int> filled;
    // for (int i : a[0]) {
    //     filled.insert(i);
    // }
    for (int i = 1; i <= s; i++) {
        if (a[1][i] <= m) {
            dp[1][a[1][i]] = 1 * i;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int j = 0; j <= m; ++j) {
            for (int i = 0; i <= s; i++) {
                if (a[k][i] <= j) {
                    dp[k][j] = max(dp[k][j], dp[k - 1][j - a[k][i]] + k * i);
                }
                else break;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= m; ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
    return 0;
}