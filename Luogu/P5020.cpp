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
    int T;
    cin >> T;
    for (int iii = 0; iii < T; ++iii) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // auto it = unique(a.begin(), a.end());
        // n = it - a.begin();
        // a.resize(n);
        int m = a[n - 1];
        vi dp(m + 1, 0);
        int ans = n;
        for (int i = 0; i <= m; i += a[0]) {
            dp[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (dp[a[i]]) {
                ans--;
                continue;
            }
            for (int j = a[i]; j <= m; ++j) {
                if (dp[j - a[i]])dp[j] = dp[j - a[i]];
            }
        }
        cout << ans << endl;
    }
    return 0;
}