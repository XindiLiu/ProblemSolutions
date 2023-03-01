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
    int  v, w;
};
struct node {
    int i, d;
    const bool operator > (const node& b) const { return d > b.d; };
};
bool cp(edge& a, edge& b) { return a.w < b.w; };
vector<list<edge>> fr;

// int dfs(int x, int p, int w) {
//     if (x == t) { return w; }
//     int ans = 0;
//     for (edge* e : fr[x]) {
//         int v = e->v == x ? e->u : e->v;
//         if (v == p)continue;
//         int a = dfs(v, x, e->w);
//         if (a != 0) {
//             ans = max(e->w, a);
//             break;
//         }
//     }
//     return ans;
// }
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
    int n, a;
    cin >> a >> n;
    vvi mx = vvi(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mx[i][j];
            if (i != j && mx[i][j] == 0) {
                mx[i][j] = a;
            }
        }
    }
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node({ 1,0 }));
    vi vis(n + 1, 0);
    vi dis(n + 1, INT_MAX);
    int ans = a;
    while (!q.empty()) {
        int i = q.top().i;
        int d = q.top().d;
        q.pop();
        if (!vis[i]) {
            vis[i] = 1;
            ans += min(d, a);
            for (int j = 1; j <= n; ++j) {
                if (i != j && !vis[j] && mx[i][j] < dis[j]) {
                    dis[j] = mx[i][j];
                    q.push(node({ j,dis[j] }));
                }
            }
        }
    }
    cout << ans;
    return 0;
}