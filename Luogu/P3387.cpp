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
struct edge {
    int u, v, w;
};
bool edcp(const edge& a, const edge& b) { return a.w < b.w; };
struct disjoint {
    vi p;
    vi sz;
    int n;
    disjoint(int inn) {
        n = inn;
        p = vi(n + 1, 0);
        sz = vi(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
    }
    int find(int a) {
        int x = a;
        while (x != p[x]) { x = p[x]; }
        p[a] = x;
        return x;
    }
    void unionset(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            if (sz[fa] < sz[fb]) {
                p[fa] = fb;
                sz[fb] += sz[fa];
            }
            else {
                p[fb] = a;
                sz[fa] += sz[fb];
            }
        }
    }
};


int n, m;

vector<list<int>> from;

vi dfn;
vi low;
vi vis;
vi cc;
vi w;
vi cw;
int cn;
stack<int> stac;
int dfncnt;

void tarjan(int x) {
    stac.push(x);
    dfn[x] = ++dfncnt;
    low[x] = dfn[x];
    vis[x] = 1;
    for (int i : from[x]) {
        if (!vis[i]) {
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if (vis[i] == 1) {
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (dfn[x] == low[x]) {
        cn++;
        while (stac.top() != x) {
            cc[stac.top()] = cn;
            cw[cn] += w[stac.top()];
            vis[stac.top()] = 2;
            stac.pop();
        }
        cc[stac.top()] = cn;
        cw[cn] += w[stac.top()];
        vis[stac.top()] = 2;
        stac.pop();
    }
}
vi dp;

vector<list<int>> fr;

int sou(int x) {
    if (dp[x] != -1) { return dp[x]; }
    dp[x] = 0;
    for (auto v : fr[x]) {
        dp[x] = max(sou(v), dp[x]);
    }
    dp[x] += cw[x];
    return dp[x];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    w = vi(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    from = vector<list<int>>(n + 1);
    vector<pii> ed(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        from[x].push_back(y);
        ed[i].first = x;
        ed[i].second = y;
    }

    dfn = vi(n + 1, 0);
    low = vi(n + 1, INT_MAX);
    vis = vi(n + 1, 0);
    cc = vi(n + 1, 0);
    cw = vi(n + 1, 0);
    cn = 0;
    dfncnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    fr = vector<list<int>>(cn + 1);
    for (int i = 0; i < m; ++i) {
        if (cc[ed[i].first] != cc[ed[i].second]) {
            fr[cc[ed[i].first]].push_back(cc[ed[i].second]);
        }
    }
    dp = vi(cn + 1, -1);
    int ans = 0;
    for (int i = 1; i <= cn; ++i) {
        if (dp[i] == -1) {
            sou(i);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}