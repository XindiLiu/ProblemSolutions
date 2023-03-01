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
    int w;
    edge(int t1, int w1) :to(t1), w(w1) {};
};
struct node {
    int i, d;
    node(int i1, int d1) :i(i1), d(d1) {};
    bool operator > (const node& a) const {
        return this->d > a.d;
    }
};
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
vi dis;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s;
    n = read();
    m = read();
    s = read();
    vi visit;
    visit = vi(n + 1, 0);
    vector<list<edge>> from;
    from = vector<list<edge>>(n + 1);

    dis = vi(n + 1, INT_MAX);
    dis[s] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        from[u].push_back(edge(v, w));
    }
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(s, 0));
    while (!q.empty()) {
        int i = q.top().i;
        q.pop();
        if (!visit[i]) {
            visit[i] = 1;
            for (auto e : from[i]) {
                if (dis[i] + e.w < dis[e.to]) {
                    dis[e.to] = min(dis[e.to], dis[i] + e.w);
                    q.push(node(e.to, dis[e.to]));
                }
            }
        }
    }
    cout << dis[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << dis[i];
    }
    return 0;
}