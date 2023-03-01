#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;

int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x;
}

struct edge {
    int a, b;
    double w;
    edge(int ina, int inb, double inw) : a(ina), b(inb), w(inw) {};
    edge() {};
};
const bool cp(edge& a, edge& b) { return a.w < b.w; };
typedef vector<list<edge>> vle;
vi p;
vi sz;
int nc;
vector<list<int>> chunks;
int find(int x) {
    int i = x;
    while (i != p[i]) {
        i = p[i];
    }
    p[x] = i;
    return i;
}
void unionset(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        nc -= 1;
        if (sz[fx] > sz[fy]) {
            p[fy] = fx;
            sz[fx] += sz[fy];
        }
        else {
            p[fx] = fy;
            sz[fy] += sz[fx];
        }
    }
}
const double dist(pii& a, pii& b) { return (double)sqrt((double)(a.first - b.first) * (a.first - b.first) + (double)(a.second - b.second) * (a.second - b.second)); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    // n = read();
    // m = read();
    cin >> n >> m;
    vector<pii> nodes = vector<pii>(n + 1);
    // vvi am = vvi(n + 1, vi(n + 1, 0));
    //chunks = vector<list<int>>(n + 1);
    p = vi(n + 1, 0);
    nc = n;
    sz = vi(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        // x = read();
        // y = read();
        cin >> x >> y;
        nodes[i] = make_pair(x, y);
        p[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        // a = read();
        // b = read();
        cin >> a >> b;
        // am[a][b] = 1;
        // am[b][a] = 1;
        unionset(a, b);
    }


    for (int i = 1; i <= n; ++i) {
        find(i);
    }
    // for (int i = 1; i <= n; ++i) { com[i] = com[p[i]]; }
    vector<edge> ed = vector<edge>(n * n);
    int e = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (find(i) != find(j)) {
                ed[e++] = edge(i, j, dist(nodes[i], nodes[j]));
            }
        }
    }
    double ans = 0;
    sort(ed.begin(), ed.begin() + e, cp);
    for (int i = 0; i < e; ++i) {
        if (find(ed[i].a) != find(ed[i].b)) {
            unionset(ed[i].a, ed[i].b);
            ans += ed[i].w;
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}