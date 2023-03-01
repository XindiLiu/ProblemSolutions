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
bool cp(edge& a, edge& b) { return a.w < b.w; };
vector<list<edge*>> fr;
int s, t;
int dfs(int x, int p, int w) {
    if (x == t) { return w; }
    int ans = 0;
    for (edge* e : fr[x]) {
        int v = e->v == x ? e->u : e->v;
        if (v == p)continue;
        int a = dfs(v, x, e->w);
        if (a != 0) {
            ans = max(e->w, a);
            break;
        }
    }
    return ans;
}
vi p;
vi sz;
int find(int x) {
    int i = x;
    while (p[i] != i) {
        i = p[i];
    }
    p[x] = i;
    return i;
}
void un(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
        if (sz[fa] < sz[fb]) { swap(fa, fb); }
        p[fb] = fa;
        sz[fa] += sz[fb];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m >> s >> t;
    vector<edge> ed(m);
    fr = vector<list<edge*>>(n + 1);
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;

    }
    sort(ed.begin(), ed.end(), cp);
    p = vi(n + 1, 0);
    sz = vi(n + 1, 1);
    for (int i = 1; i <= n; ++i) { p[i] = i; }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        if (find(ed[i].u) == find(ed[i].v))continue;
        // ans = max(ans, ed[i].w);
        fr[ed[i].u].push_back(&ed[i]);
        fr[ed[i].v].push_back(&ed[i]);
        un(ed[i].u, ed[i].v);
    }
    cout << dfs(s, 0, 0);
    return 0;
}