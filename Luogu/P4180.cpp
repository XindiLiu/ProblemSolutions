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
vvi p2;
vvi mw;
vector<list<edge>> from;
vi depth;
void dfs(int p, int x, int w) {
    p2[x][0] = p;
    mw[x][0] = w;
    if (p == 0) mw[x][0] = 0;
    depth[x] = depth[p] + 1;
    for (int k = 1; k <= log2(depth[x]); ++k) {
        p2[x][k] = p2[p2[x][k - 1]][k - 1];
        mw[x][k] = max(mw[p2[x][k - 1]][k - 1], mw[x][k - 1]);
    }
    // p2[x][0] = p;
    for (edge e : from[x]) {
        // int u = x;
        int to = e.u == x ? e.v : e.u;
        if (to != p)dfs(x, to, e.w);
    }
}
// int lca(int a, int b) {
//     if (depth[a] > depth[b]) { swap(a, b); }
//     while (depth[a] < depth[b]) {
//         int k = log2(depth[b] - depth[a]);
//         b = p2[b][k];
//     }
//     if (a == b) { return a; }
//     for (int k = log2(depth[a]); k >= 0; --k) {
//         if (p2[a][k] != p2[b][k]) {
//             a = p2[a][k];
//             b = p2[b][k];
//         }
//     }
//     return p2[a][0];
// }

ll maxw(int a, int b, int w) {
    if (depth[a] > depth[b]) { swap(a, b); }
    int ans = 0;
    while (depth[a] < depth[b]) {
        int k = log2(depth[b] - depth[a]);
        if (mw[b][k] < w)ans = max(ans, mw[b][k]);
        b = p2[b][k];

    }

    if (a == b) { return ans; }
    for (int k = log2(depth[a]); k >= 0; --k) {
        if (p2[a][k] != p2[b][k]) {
            if (mw[a][k] < w)ans = max(ans, mw[a][k]);
            if (mw[b][k] < w)ans = max(ans, mw[b][k]);
            a = p2[a][k];
            b = p2[b][k];

        }
    }
    if (mw[a][0] < w)ans = max(ans, mw[a][0]);
    if (mw[b][0] < w)ans = max(ans, mw[b][0]);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    vector<edge> eds = vector<edge>(m + 1);
    for (int i = 1; i <= m; ++i) {
        // int x, y, z;
        cin >> eds[i].u >> eds[i].v >> eds[i].w;
    }
    sort(eds.begin() + 1, eds.end(), edcp);
    from = vector<list<edge>>(n + 1);
    //kruskal
    disjoint dj = disjoint(n);
    ll mst = 0;
    vi intree = vi(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        if (dj.find(eds[i].u) != dj.find(eds[i].v)) {
            dj.unionset(eds[i].u, eds[i].v);
            from[eds[i].u].push_back(eds[i]);
            from[eds[i].v].push_back(eds[i]);
            mst += (ll)eds[i].w;
            intree[i] = 1;
        }
    }

    //lca
    depth = vi(n + 1, 0);
    p2 = vvi(n + 1, vi(log2(n) + 1, 0));
    mw = vvi(n + 1, vi(log2(n) + 1, 0));
    dfs(0, 1, 0);
    ll ans = INT64_MAX;
    for (int i = 1; i <= m; ++i) {
        if (!intree[i] && eds[i].u != eds[i].v) {
            ll diff = (ll)eds[i].w - maxw(eds[i].u, eds[i].v, eds[i].w);
            if (diff > 0) {
                ans = min(ans, diff);
            }
        }
    }
    cout << mst + ans;
    return 0;
}