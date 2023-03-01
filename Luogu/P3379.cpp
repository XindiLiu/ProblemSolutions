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
int numedge = 0;
vi head;
vector<edge> edges;
vi p;
vvi p2;
vi depth;
void addedge(int a, int b) {
    numedge++;
    edges[numedge] = edge(b, head[a]);
    head[a] = numedge;

}
void crash() {
    crash();
}
void dfs(int x) {
    for (int e = head[x]; e != 0; e = edges[e].next) {
        int i = edges[e].to;
        if (i != p[x]) {
            p[i] = x;
            p2[i][0] = x;
            depth[i] = depth[x] + 1;
            int lo2 = log2(depth[i]);
            for (int k = 1; k <= lo2; ++k) {
                p2[i][k] = p2[p2[i][k - 1]][k - 1];
            }

            dfs(i);
        }
    }
}
int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        swap(a, b);
    }
    while (depth[b] > depth[a]) {
        int k = floor(log2(depth[b] - depth[a]));
        b = p2[b][k];
    }
    if (a == b) {

        return a;
    }

    for (int k = floor(log2(depth[a])); k >= 0; --k) {
        if (p2[a][k] != p2[b][k]) {
            a = p2[a][k];
            b = p2[b][k];
        }
    }
    if (p2[a][0] == 0) {
        crash();
    }
    return p2[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    head = vi(n + 1, 0);
    edges = vector<edge>(2 * n);
    p2 = vvi(n + 1, vi(log2(n) + 1, 0));
    p = vi(n + 1, 0);
    depth = vi(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        addedge(a, b);
        addedge(b, a);
    }

    dfs(s);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
    }
    return 0;
}