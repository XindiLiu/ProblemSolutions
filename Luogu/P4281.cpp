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
    int to;
    int next;
    edge(int to1, int next1) : to(to1), next(next1) {};
    edge() {};
};
vector<edge> edges;
vi head;
vi depth;
vi logn;
vvi p2;
int numedge = 0;
void addedge(int a, int b) {
    numedge++;
    edges[numedge] = edge(b, head[a]);
    head[a] = numedge;
}
void build(int pa, int x) {
    // p2[x][0] = pa;
    for (int e = head[x]; e != 0; e = edges[e].next) {
        int i = edges[e].to;
        if (i != pa) {
            p2[i][0] = x;
            // c2[i][0] = x;
            depth[i] = depth[x] + 1;
            for (int k = 1; k <= logn[depth[i]]; ++k) {
                p2[i][k] = p2[p2[i][k - 1]][k - 1];
            }
            build(x, i);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) { swap(a, b); }
    while (depth[a] < depth[b]) {
        int k = logn[depth[b] - depth[a]];
        b = p2[b][k];
    }
    if (a == b) { return a; }
    for (int k = logn[depth[a]]; k >= 0; --k) {
        if (p2[a][k] != p2[b][k]) {
            a = p2[a][k];
            b = p2[b][k];
        }
    }
    return p2[a][0];
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
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    // cin >> n >> m;
    n = read();
    m = read();
    logn = vi(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        logn[i] = logn[i >> 1] + 1;
    }
    head = vi(n + 1, 0);
    edges = vector<edge>(2 * n);
    p2 = vvi(n + 1, vi(logn[n] + 1, 0));
    depth = vi(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        // cin >> a >> b;
        a = read();
        b = read();
        addedge(a, b);
        addedge(b, a);
    }
    int root = 1;
    build(0, root);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        // cin >> a >> b >> c;
        a = read();
        b = read();
        c = read();
        // let depth[a]<depth[b]<depth[c]
        if (depth[a] > depth[b]) { swap(a, b); }
        if (depth[b] > depth[c]) {
            swap(b, c);
        }
        if (depth[a] > depth[b]) { swap(a, b); }

        int ab = lca(a, b);
        int bc = lca(b, c);
        int ac = lca(a, c);
        int ans1;
        int ans2;
        if (depth[ab] >= depth[bc] && depth[ab] >= depth[ac]) {
            ans1 = ab;
            // ans2 = dist(a, b) + dist(ab, c);
            // ans2 = depth[a] + depth[b] - 2 * depth[ab] + depth[ab] + depth[c] - 2 * depth[bc];
            ans2 = depth[a] + depth[b] + depth[c] - depth[ab] - 2 * depth[bc];
        }
        else if (depth[bc] >= depth[ab] && depth[bc] >= depth[ac]) {
            ans1 = bc;
            // ans2 = dist(b, c) + dist(bc, a);
            ans2 = depth[a] + depth[b] + depth[c] - depth[bc] - 2 * depth[ab];
        }
        else if (depth[ac] >= depth[ab] && depth[ac] >= depth[bc]) {
            ans1 = ac;
            // ans2 = dist(a, c) + dist(ac, b);
            ans2 = depth[a] + depth[b] + depth[c] - depth[ac] - 2 * depth[bc];
        }
        // }

        // cout << ans1 << ' ' << ans2 << endl;
        printf("%d %d\n", ans1, ans2);
    }

    return 0;
}