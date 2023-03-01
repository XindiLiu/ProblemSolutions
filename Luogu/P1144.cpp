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
    int n, m;
    n = read();
    m = read();
    vi visit;
    visit = vi(n + 1, 0);
    vector<list<edge>> from;
    from = vector<list<edge>>(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        u = read();
        v = read();
        if (u != v) {
            from[u].push_back(edge(v, 1));
            from[v].push_back(edge(u, 1));
        }
    }

    priority_queue<node, vector<node>, greater<node>> q;
    int s = 1;
    dis = vi(n + 1, INT_MAX);
    dis[s] = 0;
    q.push(node(s, 0));
    vi count(n + 1, 0);
    count[s] = 1;
    while (!q.empty()) {
        int i = q.top().i;
        q.pop();
        if (!visit[i]) {
            visit[i] = 1;
            for (auto e : from[i]) {
                if (dis[i] + e.w < dis[e.to]) {
                    dis[e.to] = min(dis[e.to], dis[i] + e.w);
                    count[e.to] = count[i];
                    q.push(node(e.to, dis[e.to]));
                }
                else if (dis[i] + e.w == dis[e.to]) {
                    count[e.to] = ((ll)count[e.to] + (ll)count[i]) % (ll)100003;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (dis[i] == INT_MAX) {
            cout << 0 << endl;
        }
        else
            cout << count[i] << endl;
    }
    return 0;
}