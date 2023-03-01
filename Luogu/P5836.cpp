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
const char hc = 'H';
const char gc = 'G';
vi cow;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    cow = vi(n + 1);
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        cow[i] = c;
    }
    vector<list<int>> connections(n + 1, list<int>());
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }

    vi depth = vi(n + 1, -1);
    int root = 1;
    depth[root] = 0;
    queue<int> q = queue<int>();
    q.push(root);
    vvi fa = vvi(n + 1, vi(log2(n) + 1, 0));
    vvi g = vvi(n + 1, vi(log2(n) + 1, 0));
    vvi h = vvi(n + 1, vi(log2(n) + 1, 0));
    g[root][0] = (cow[root] == gc);
    h[root][0] = (cow[root] == hc);
    while (!q.empty()) {
        int i = q.front();
        for (auto it = connections[i].begin(); it != connections[i].end(); ++it) {
            int j = *it;
            // if (tree[j].parent != -1) {
            if (depth[j] == -1) {
                // tree[j].parent = i;
                // tree[j].depth = tree[i].depth + 1;
                depth[j] = depth[i] + 1;
                q.push(j);

                fa[j][0] = i;
                g[j][0] = (cow[i] == gc || cow[j] == gc);
                h[j][0] = (cow[i] == hc || cow[j] == hc);
                int k = 1;
                int k2 = 2;
                while (k2 <= depth[j]) {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                    g[j][k] = (g[j][k - 1] || g[fa[j][k - 1]][k - 1]);
                    h[j][k] = (h[j][k - 1] || h[fa[j][k - 1]][k - 1]);
                    k++;
                    k2 = k2 << 1;
                }
            }
        }
        q.pop();
    }


    string ans = string(m, '0');
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (a == b) {
            ans[i] = (cow[a] == c) ? '1' : '0';
            continue;
        }
        else {
            if (depth[a] > depth[b]) {
                swap(a, b);
            } // now depth[a] < depth[b]
            int j = b;
            while (depth[j] > depth[a]) {
                int k = log2(depth[j] - depth[a]);
                if ((c == gc) ? g[j][k] : h[j][k]) {
                    ans[i] = '1';
                    // break;
                    goto cont;
                }
                j = fa[j][k];
            }
            b = j;
            if (a == b) {
                goto cont;
            }

            for (int k = log2(depth[a]); k >= 0; --k) {
                if (fa[a][k] != fa[b][k]) {
                    if ((c == gc) ? (g[a][k] || g[b][k]) : (h[a][k] || h[b][k])) {
                        ans[i] = '1';
                        // break;
                        goto cont;
                    }
                    a = fa[a][k];
                    b = fa[b][k];
                }
            }

            if ((c == gc) ? (g[a][0] || g[b][0]) : (h[a][0] || h[b][0])) {
                ans[i] = '1';
            }
        cont:
            continue;

        }
    }
    cout << ans;
    return 0;
}