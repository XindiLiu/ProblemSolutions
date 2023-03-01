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
typedef vector<list<int>> vli;
vi r;
vli c;
pii dp(int i) {
    if (c[i].empty()) {
        return make_pair(r[i], 0);
    }

    int sumf = r[i]; // sum of r if i comes
    int sums = 0; // sum of r if i does not come
    for (int x : c[i]) {
        pii xr = dp(x);
        sumf += xr.second;
        sums += max(xr.first, xr.second);
    }
    return make_pair(sumf, sums);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    r = vi(n + 1);
    c = vli(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    vi parent(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        c[b].push_back(a);
        parent[a]++;
    }
    int xz;
    for (int i = 1; i <= n; ++i) {
        if (!parent[i]) {
            xz = i;
            break;
        }
    }
    pii ans = dp(xz);
    cout << max(ans.first, ans.second);
    return 0;
}