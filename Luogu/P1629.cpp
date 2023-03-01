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
typedef vector<list<edge>> vle;
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

int n, m;
vi visit;
ll sum = 0;
void dij(vle& from) {
    int s = 1;
    vi dis;
    dis = vi(n + 1, INT_MAX);
    dis[s] = 0;
    priority_queue<node, vector<node>, greater<node>> q;
    q.push(node(s, 0));
    while (!q.empty()) {
        int i = q.top().i;
        q.pop();
        if (!visit[i]) {
            for (auto e : from[i]) {
                if (dis[i] + e.w < dis[e.to]) {
                    dis[e.to] = min(dis[e.to], dis[i] + e.w);
                    q.push(node(e.to, dis[e.to]));
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        sum += (ll)dis[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    n = read();
    m = read();

    visit = vi(n + 1, 0);
    vle from1, from2;
    from1 = vle(n + 1);
    from2 = vle(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        from1[u].push_back(edge(v, w));
        from2[v].push_back(edge(u, w));
    }
    dij(from1);
    dij(from2);
    cout << sum;
    return 0;
}