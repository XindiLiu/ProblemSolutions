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
int n, m;
struct edge {
    int fr, to, w, t;
    edge(int fr1, int to1, int w1, int t1) : fr(fr1), to(to1), w(w1), t(t1) {};
    edge() {};
    // bool operator < (const edge& e) const { return this->t > e.t; };
};
bool operator < (const edge& a, const edge& b) { return a.t < b.t; };
struct node {
    int i, d;
    node(int i1, int d1) : i(i1), d(d1) {};
    bool operator > (const node& e) const { return this->d > e.d; };
};
// vector<list<int>> from;
// vector<edge> edges;
vvi dis;
vi visdis;
vi tv;
int ct;
int k;
void floyd() {
    for (; k < n && tv[k] <= ct; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (((ll)dis[i][k] + (ll)dis[k][j]) < (ll)dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
// int dij(int x, int y, int t) {
//     if (!visdis[x] && !visdis[y]) {
//         visdis[x] = 1;
//         visdis[y] = 1;
//         priority_queue<node, vector<node>, greater<node>> q;
//         vi vis = vi(n, 0);
//         dis[x][x] = 0;
//         q.push(node(x, 0));
//         while (!q.empty()) {
//             int cur = q.top().i;
//             q.pop();
//             if (!vis[cur]) {
//                 vis[cur] = 1;
//                 for (auto it = from[cur].begin(); it != from[cur].end() && edges[*it].t <= t; ++it) {
//                     int to = (cur == edges[*it].fr) ? edges[*it].to : edges[*it].fr;
//                     int w = edges[*it].w;
//                     if (dis[x][cur] + w < dis[x][to]) {
//                         dis[x][to] = dis[x][cur] + w;
//                         q.push(node(to, dis[x][to]));
//                     }
//                 }
//             }
//         }
//         if (dis[x][y] == INT_MAX) {
//             return -1;
//         }
//         else { return dis[x][y]; }
//     }
//     else {
//         if (!visdis[x]) { swap(x, y); }
//         if (dis[x][y] == INT_MAX) {
//             return -1;
//         }
//         else { return dis[x][y]; }

//     }

// }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q;
    n = read();
    m = read();
    // cin >> n >> m;
    tv = vi(n);
    visdis = vi(n);
    // from = vector<list<int>>(n);
    // edges = vector<edge>(m);
    dis = vvi(n, vi(n, INT_MAX));
    k = 0;
    ct = 0;
    for (int i = 0; i < n; ++i) {
        tv[i] = read();
        dis[i][i] = 0;
        // cin >> tv[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        dis[u][v] = w;
        dis[v][u] = w;
        // cin >> u >> v >> w;
        // edges[i] = edge(u, v, w, max(tv[u], tv[v]));
        // from[u].push_back(edge(v, w, max(tv[u], tv[v])));
        // from[v].push_back(edge(u, w, max(tv[u], tv[v])));
    }
    // sort(edges.begin(), edges.end());
    // for (int i = 0; i < m; ++i) {
    //     from[edges[i].fr].push_back(i);
    //     from[edges[i].to].push_back(i);
    //     // from[u].push_back(edge(v, w, max(tv[u], tv[v])));
    //     // from[v].push_back(edge(u, w, max(tv[u], tv[v])));
    // }
    q = read();
    // cin >> q;
    floyd();
    for (int i = 0; i < q; ++i) {
        int x, y, t;
        x = read();
        y = read();
        t = read();
        // cin >> x >> y >> t;
        if (ct < t) {
            ct = t;
            floyd();
        }
        int ans;
        if (dis[x][y] == INT_MAX || tv[x] > t || tv[y] > t) { ans = -1; }
        else { ans = dis[x][y]; }
        cout << ans << endl;
    }
    return 0;
}