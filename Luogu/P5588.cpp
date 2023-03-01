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
vi end1;
vi end2;
vi head1;

vvi p2;
vi color;
vi nsub;
vi stats;
int numedge = 0;
void addedge(int a, int b) {
    numedge++;
    edges[numedge] = edge(b, head[a]);
    head[a] = numedge;
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
void dfs(int pa, int x) {
    // p2[x][0] = pa;
    nsub[x] = 1;
    int cx = color[x];
    if (stats[cx] == 2) {}

    else if (end1[cx] == 0) {
        head1[cx] = x;
        end1[cx] = x;
    }
    else if (end1[cx] != 0 && end2[cx] != 0) {
        int a1 = lca(x, end1[cx]);
        int a2 = lca(x, end2[cx]);
        if (a1 == end1[cx]) { end1[cx] = x; }
        else if (a2 == end2[cx]) { end2[cx] = x; }
        else {
            stats[cx] = 2;
        }
    }

    else if (end1[cx] != 0 && end2[cx] == 0) {
        int a1 = lca(x, end1[cx]);
        if (a1 == end1[cx]) { end1[cx] = x; }
        else if (depth[a1] <= depth[head1[cx]]) {
            head1[cx] = a1;
            end2[cx] = x;
        }
        else {
            stats[cx] = 2;
        }
    }

    for (int e = head[x]; e != 0; e = edges[e].next) {
        int i = edges[e].to;
        if (i != pa) {
            p2[i][0] = x;
            // c2[i][0] = x;
            depth[i] = depth[x] + 1;
            for (int k = 1; k <= logn[depth[i]]; ++k) {
                p2[i][k] = p2[p2[i][k - 1]][k - 1];
            }
            dfs(x, i);
            nsub[x] += nsub[i];
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

void crash() { crash(); }
int main() {
    ios_base::sync_with_stdio(false);
    // for (int root = 1; root <= 10; ++root) {


    int n, m;
    // cin >> n >> m;
    n = read();

    color = vi(n + 1, 0);
    nsub = vi(n + 1, 0);
    head1 = vi(n + 1, 0);
    end1 = vi(n + 1, 0);
    end2 = vi(n + 1, 0);
    head = vi(n + 1, 0);
    edges = vector<edge>(2 * n);
    depth = vi(n + 1, 0);
    stats = vi(n + 1, 0);
    logn = vi(n + 1, 0);
    for (int i = 2; i <= n; ++i) { logn[i] = logn[i >> 1] + 1; }
    p2 = vvi(n + 1, vi(logn[n] + 1, 0));

    for (int i = 1; i <= n; ++i) {
        color[i] = read();
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        a = read();
        b = read();
        addedge(a, b);
        addedge(b, a);
    }
    int root = 1;
    dfs(0, root);
    ll maxpath = (ll)n * (ll)(n - 1) / (ll)2;
    for (int c = 1; c <= n; ++c) {
        ll ans = 0;
        if (stats[c] == 2) { ans = 0; }
        else if (end1[c] == 0) { ans = maxpath; }
        else if (end2[c] == 0) {

            int a = head1[c];
            int b = end1[c];
            if (a == b) {
                // ans = maxpath - ((ll)(n - nsub[b]) * (ll)(n - nsub[b] - 1) / (ll)2);
                ans = (ll)(n - nsub[b]) * (ll)(nsub[b]);
                int bn = 0;

                for (int e = head[b]; e != 0; e = edges[e].next) {
                    int i = edges[e].to;
                    if (i != p2[b][0]) {
                        for (int f = head[b]; f != e; f = edges[f].next) {
                            int j = edges[f].to;
                            if (j != p2[b][0]) {
                                ans += (ll)nsub[i] * (ll)nsub[j];
                            }
                        }
                    }
                }
                ans += (ll)(nsub[b] - 1);

            }
            else {
                while (depth[a] + 1 < depth[b]) {
                    int k = logn[depth[b] - depth[a] - 1];
                    b = p2[b][k];
                }
                ans = (ll)nsub[end1[c]] * (ll)(n - nsub[b]);
            }

        }
        else if (end2[c] != 0) {
            ans = (ll)nsub[end1[c]] * (ll)nsub[end2[c]];
        }

        cout << ans << endl;
    }
    // }

    return 0;
}