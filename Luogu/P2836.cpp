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

vi dfn, low, cc, vis;
int df, cn, ans;
vector<list<int>> fr;
stack<int> s;
void tarjan(int u) {
    dfn[u] = low[u] = ++df;
    vis[u] = 1;
    s.push(u);
    for (int v : fr[u]) {
        if (!vis[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v] == 1) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        cn++;
        if (s.top() == u) {
            cc[u] = cn;
            vis[u] = 2;
            s.pop();
            return;
        }
        ans++;
        while (s.top() != u) {
            cc[u] = cn;
            vis[u] = 2;
            s.pop();
        }
        cc[u] = cn;
        vis[u] = 2;
        s.pop();
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    fr = vector<list<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        fr[b].push_back(a);
    }
    dfn = vi(n + 1, 0);
    low = vi(n + 1, INT_MAX);
    cc = vi(n + 1, 0);
    vis = vi(n + 1, 0);
    df = 0;
    cn = 0;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) { tarjan(i); }
    }
    cout << ans;
    return 0;
}