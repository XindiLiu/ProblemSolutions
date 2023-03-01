#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
// typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
struct pii { int f, s; };
// bool cp(pii& a, pii& b) { return max(a.f, a.s) < max(b.f, b.s); };
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    vvi sz(n, vi(m + 1, 0));
    vi szz(n);
    string in;
    for (int j = 0; j < n; ++j) {
        cin >> in;
        char a = in[0];
        int l = 1;
        int rt = 0;
        for (int i = 1; i < m; ++i) {
            if (in[i] != a) {
                a = in[i];
                rt++;
                sz[j][rt] = l;
                l = 1;

            }
            else l++;
        }
        rt++;
        sz[j][rt] = l;
        szz[j] = rt;
    }
    vector<vector<vector<pii>>> dp(n, vector<vector<pii>>(t + 1, vector<pii>(m + 1, {0,0})));
    vector<vector<int>> f(n, vi(t + 1, 0));
    vector<vector<int>> p(n, vi(t + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= min(szz[i], t); ++j) {
            // dp[i][j][j], 1) = dp[i][j - 1][j - 1], 1) + sz[i][j];
            // dp[i][j][j], 0) = dp[i][j - 1][j - 1], 1);
            for (int k = j; k <= szz[i]; ++k) {
                dp[i][j][k].f = max(dp[i][j][k - 1].s, dp[i][j - 1][k - 1].f) + sz[i][k];
                dp[i][j][k].s = max(dp[i][j][k - 1].f, dp[i][j - 1][k - 1].s);
                f[i][j] = max(f[i][j], max(dp[i][j][k].f, dp[i][j][k].s));
            }
        }
    }


    int sumsz = szz[0];
    for (int i = 0; i <= min(t, szz[0]); ++i) {
        p[0][i] = f[0][i];
    }
    for (int i = 1; i < n; ++i) {
        sumsz += szz[i];
        for (int j = 0; j <= min(sumsz, t); ++j) {
            for (int k = 0; k <= min(szz[i], j); ++k) {
                p[i][j] = max(p[i][j], p[i - 1][j - k] + f[i][k]);
            }
        }
    }
    cout << *max_element(p[n - 1].begin(), p[n - 1].end());
    return 0;
}