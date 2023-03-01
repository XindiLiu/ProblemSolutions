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
    int to, w;
    edge(int to1, int w1) : to(to1), w(w1) {};
};

vi diameter;
vi dis; // distance from root
vi p; // parent nodes
vector<list<edge>> from;
int far; // node with longest distance from root
void dfs(int pa, int x) {
    p[x] = pa;
    if (dis[x] > dis[far]) {
        far = x;
    }
    for (auto it = from[x].begin(); it != from[x].end(); ++it) {
        int j = it->to;
        if (j == pa || diameter[j]) { // if j is the parent or is inthe diameter.
            continue;
        }
        dis[j] = dis[x] + it->w;
        dfs(x, j);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, s;
    cin >> n >> s;
    from = vector<list<edge>>(n + 1, list<edge>());
    p = vi(n + 1, 0); // parent
    diameter = vi(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        from[u].push_back(edge(v, w));
        from[v].push_back(edge(u, w));
    }
    if (n == 2) {
        cout << ((from[1].front().w < s) ? 0 : from[1].front().w);
        return 0;
    }

    far = 0;
    dis = vi(n + 1, 0);
    dis[1] = 1;
    dfs(0, 1);
    dis[far] = 0;
    dfs(0, far);
    int top = far;


    int ans = INT_MAX;
    int maxdis;
    // if longest distance is inside of the diameter:
    for (int i = top, j = top; i != 0; i = p[i]) {
        while (dis[j] - dis[i] > s) {
            j = p[j];
        }
        maxdis = max(dis[top] - dis[j], dis[i]);
        ans = min(ans, maxdis);
    }


    // if longest distance is outside of the diameter:

    for (int i = top; i != 0; i = p[i]) {
        diameter[i] = 1;
    }
    for (int i = top; i != 0; i = p[i]) { // for all nodes in diameter, compute the longest distance to it.
        far = i;
        dis[far] = 0;
        dfs(p[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i]);
    }
    cout << ans;
    return 0;
}