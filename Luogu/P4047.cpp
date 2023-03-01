#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
struct node {
    double d;
    int i;
    node(int i1, double d1) :i(i1), d(d1) {};
    bool operator > (const node& a) const {
        return this->d > a.d;
    }
    bool operator < (const node& a) const {
        return this->d < a.d;
    }
};
struct edge {
    double w;
    int u, v;
    edge(int u1, int v1, double w1) :u(u1), v(v1), w(w1) {};
    bool operator > (const edge& a) const {
        return this->w > a.w;
    }
};
struct cp {
    bool operator() (const pii& a, const pii& b) { return a.first < b.first; }
};
const double dist(pii& a, pii& b) { return (double)sqrt((double)(a.first - b.first) * (a.first - b.first) + (double)(a.second - b.second) * (a.second - b.second)); }
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int s, n;
    cin >> n >> s;
    vector<pii> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].first >> nodes[i].second;
    }
    priority_queue<node, vector<node>, greater<node>> p;
    priority_queue<node, vector<node>, greater<node>> q;
    int root = 0;
    vd dis = vd(n, INT_MAX);
    dis[root] = 0;
    q.push(node(root, 0));
    vi vis = vi(n + 1, 0);
    double ans = 0;
    while (!q.empty()) {
        int i = q.top().i;
        double d = q.top().d;
        q.pop();
        if (!vis[i]) {
            if ((p.size() < s || d > p.top().d) && d != 0) {
                p.push(node(i, d));
                if (p.size() > s) {
                    p.pop();
                }
            }
            vis[i] = 1;
            ans += d;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && i != j) {
                    double w = dist(nodes[i], nodes[j]);
                    if (w < dis[j]) {
                        dis[j] = w;
                        q.push(node(j, dis[j]));
                    }
                }
            }
        }

    }
    p.pop();
    if (n < s) {
        cout << 0;
    }
    else {
        cout << setiosflags(ios::fixed) << setprecision(2) << p.top().d;
    }
    return 0;
}