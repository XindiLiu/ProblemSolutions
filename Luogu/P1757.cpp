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
struct item {
    int w;
    int v;
    // int g;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<list<item>> group(n + 1);
    int gn = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        group[c].push_back(item({ a,b }));
        gn = max(gn, c);
    }
    vi dp(m + 1, 0);
    for (int g = 1; g <= gn; ++g) {
        for (int w = m; w >= 0; --w) {
            for (item i : group[g]) {
                if (w >= i.w) {
                    dp[w] = max(dp[w], dp[w - i.w] + i.v);
                }

            }
        }
    }
    cout << dp[m];

    return 0;
}