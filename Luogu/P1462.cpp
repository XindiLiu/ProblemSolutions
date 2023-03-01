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

int n, m, b;
vi f;
vi fo;
vector<list<edge>> from;
ll dij(int k) {
    vi visit;
    visit = vi(n + 1, 0);
    vll dis;
    dis = vll(n + 1, INT64_MAX);
    dis[1] = 0;
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(1, 0));
    while (!q.empty()) {
        int i = q.top().i;
        q.pop();
        if (!visit[i]) {
            visit[i] = 1;
            for (auto e : from[i]) {
                if (f[fo[k]] >= f[e.to] && dis[i] + (ll)e.w < dis[e.to]) {
                    dis[e.to] = min(dis[e.to], dis[i] + (ll)e.w);
                    q.push(node(e.to, dis[e.to]));
                }
            }
        }
    }
    return dis[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    n = read();
    m = read();
    b = read();

    f = vi(n + 1, 0);
    fo = vi(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        f[i] = read();
        fo[i] = i;
    }
    sort(fo.begin() + 1, fo.end(), [&] (int x, int y) {return f[x] < f[y]; });

    from = vector<list<edge>>(n + 1);


    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        from[u].push_back(edge(v, w));
        from[v].push_back(edge(u, w));
    }
    int l = 1, r = n + 1;
    for (int i = 1; i <= n; ++i) {
        if (fo[i] == 1)l = max(l, i);
        if (fo[i] == n)l = max(l, i);
    }
    int minf = INT_MAX;
    int minc = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        ll a = dij(mid);
        if (a > (ll)b) {
            l = mid + 1;
        }
        else {
            minc = fo[mid];
            minf = f[minc];
            r = mid;
        }
        if (l == r)break;
    }
    if (minf == INT_MAX) {
        cout << "AFK";
    }
    else { cout << minf; }
    return 0;
}