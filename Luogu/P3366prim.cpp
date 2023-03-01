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
struct node {
    double d;
    int i;
    node(int i1, double d1) :i(i1), d(d1) {};
    bool operator > (const node& a) const {
        return this->d > a.d;
    }
};
struct edge {
    int w;
    int to;
    edge(int u1, int w1) :to(u1), w(w1) {};
    bool operator > (const edge& a) const {
        return this->w > a.w;
    }
};
const bool cp(edge& a, edge& b) { return a.w < b.w; };
typedef vector<list<edge>> vle;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    n = read();
    m = read();
    vle ed = vle(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        x = read();
        y = read();
        z = read();
        ed[x].push_back(edge(y, z));
        ed[y].push_back(edge(x, z));
    }
    priority_queue<edge, vector<edge>, greater<edge>> q;
    int root = 1;
    vi dis = vi(n + 1, INT_MAX);
    vi vis = vi(n + 1, 0);
    dis[root] = 0;
    q.push(edge(root, 0));
    int ans = 0;
    while (!q.empty()) {
        int i = q.top().to;
        int d = q.top().w;
        q.pop();
        if (!vis[i]) {
            vis[i] = 1;
            ans += d;
            for (edge e : ed[i]) {
                int j = e.to;
                int w = e.w;
                if (w < dis[j] && !vis[j]) {
                    dis[j] = w;
                    q.push(e);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cout << "orz";
            return 0;
        }
    }
    cout << ans;
    return 0;
}