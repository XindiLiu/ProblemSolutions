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

void tarjan(int x, int p) {
    stac.push(x);
    dfn[x] = ++dfncnt;
    low[x] = dfn[x];
    vis[x] = 1;
    int ch = 0;
    for (int i : from[x]) {
        if (!vis[i]) {
            ch++;

            tarjan(i, x);
            low[x] = min(low[x], low[i]);
            if (p != x && low[i] >= dfn[x] && !cc[x]) {
                cc[x] = 1;
                cn++;
            }
        }
        else if (x != p) {
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (x == p && ch >= 2 && !cc[x]) {
        cc[x] = 1;
        cn++;
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    w = vi(n + 1);
    from = vector<list<int>>(n + 1);
    vector<pii> ed(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        from[x].push_back(y);
        from[y].push_back(x);
    }

    dfn = vi(n + 1, 0);
    low = vi(n + 1, INT_MAX);
    vis = vi(n + 1, 0);
    cc = vi(n + 1, 0);
    // cw = vi(n + 1, 0);
    cn = 0;
    dfncnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    cout << cn << endl;
    for (int i = 1; i <= n; ++i) {
        if (cc[i]) {
            cout << i << ' ';
        }
    }
    return 0;
}