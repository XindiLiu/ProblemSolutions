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

int read() {
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x;
}

struct edge {
    int a, b, w;
    edge(int ina, int inb, int inw) : a(ina), b(inb), w(inw) {};
    edge() {};
};
const bool cp(edge& a, edge& b) { return a.w < b.w; };
typedef vector<list<edge>> vle;
vi p;
vi sz;
vi ans;
int find(int x) {
    int i = x;
    while (i != p[i]) {
        i = p[i];
    }
    p[x] = i;
    return i;
}
void unionset(int x, int y, int z) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        if (sz[fx] > sz[fy]) {
            p[fy] = fx;
            sz[fx] += sz[fy];
            ans[fx] += ans[fy] + z;
        }
        else {
            p[fx] = fy;
            sz[fy] += sz[fx];
            ans[fy] += ans[fx] + z;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    n = read();
    m = read();
    vector<edge> ed = vector<edge>(m);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        x = read();
        y = read();
        z = read();
        ed[i] = edge(x, y, z);
    }
    sort(ed.begin(), ed.end(), cp);
    p = vi(n + 1, 0);
    ans = vi(n + 1, 0);
    sz = vi(n + 1, 1);
    for (int i = 1; i <= n; ++i) { p[i] = i; }
    int in = 0;

    for (int i = 0; i < m; ++i) {
        if (p[ed[i].a] == p[ed[i].b])continue;
        else {
            unionset(ed[i].a, ed[i].b, ed[i].w);
        }

    }
    int com = 0;
    int pa;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) {
            pa = i;
            com++;
        }
    }
    if (com == 1) {
        cout << ans[pa];
    }
    else {
        cout << "orz";
    }
    return 0;
}