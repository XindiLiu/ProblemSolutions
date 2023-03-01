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
const ll mod = 1e8;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    int f;
    cin >> n >> f;
    // ll sum = 0;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i] % f;
        // sum += (ll)a[i];
    }
    // ll m = (sum / f) * f;
    vvi dp(n + 1, vi(f));
    dp[0][a[0]] = 1;

    for (int i = 1; i < n; ++i) {
        dp[i][a[i]] = 1;
        for (ll j = 0; j < f; ++j) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][(j - a[i] + f) % f]) % mod;
        }
    }

    cout << dp[n - 1][0];
    return 0;
}