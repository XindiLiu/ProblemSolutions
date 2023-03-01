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

struct child {
    int n;
    int sum;
};

vi a;
vector<list<child>> fr;
int dp(int x, int p) {
    int ans = a[x];
    for (auto it = fr[x].begin(); it != fr[x].end(); it++) {
        if (it->n == p) { continue; }
        else if (it->sum == INT_MIN) {
            it->sum = dp(it->n, x);
        }
        if (it->sum > 0) {
            ans += it->sum;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    a = vi(n + 1);
    fr = vector<list<child>>(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        fr[u].push_back({v,INT_MIN});
        fr[v].push_back({u,INT_MIN});
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int root = i;
        ans = max(ans, dp(root, 0));
    }

    cout << ans;
    return 0;
}