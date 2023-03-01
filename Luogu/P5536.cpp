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
vi dis;
vi p;
vi w;
vi ss;
vi dia;
void addedge(int a, int b) {
    numedge++;
    edges[numedge] = edge(b, head[a]);
    head[a] = numedge;

}
void crash() {
    crash();
}
void dfs(int pa, int x, int& k) {
    p[x] = pa;
    if (dis[x] > dis[k]) {
        k = x;
    }
    for (int e = head[x]; e != 0; e = edges[e].next) {
        int i = edges[e].to;
        if (i != p[x] && !dia[i]) {
            dis[i] = dis[x] + 1;
            dfs(x, i, k);
        }
    }
}
void dfs2(int pa, int x) {
    p[x] = pa;
    dis[x] = 0;
    for (int e = head[x]; e != 0; e = edges[e].next) {
        int i = edges[e].to;
        if (i != p[x] && !dia[i]) {
            // dis[i] = dis[x] + 1;
            dfs2(x, i);
            dis[x] = max(dis[x], dis[i] + 1);
        }
    }
}
struct comp {
    bool operator ()(const int& a, const int& b) {
        return dis[a] < dis[b];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    head = vi(n + 1, 0);
    edges = vector<edge>(2 * n);
    dis = vi(n + 1, 0);
    p = vi(n + 1, 0);
    ss = vi(n + 1, 0);
    w = vi(n + 1, 0);
    dia = vi(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        addedge(a, b);
        addedge(b, a);
    }
    int k1 = 1;

    dfs(0, 1, k1);

    int k2 = k1;
    dis[k1] = 0;
    dfs(0, k1, k2);
    int epic = (dis[k2] + 2) / 2;
    int j = k2;
    for (int i = 1; i < epic; ++i) {
        j = p[j];
    }
    epic = j;
    // dis[epic] = 0;
    dfs2(0, epic);
    priority_queue<int, vi, comp> q;

    q.push(epic);
    for (int iii = 0; iii < m; ++iii) {
        int x = q.top();
        q.pop();
        dis[x] = 0;
        for (int e = head[x]; e != 0; e = edges[e].next) {
            int i = edges[e].to;
            if (i != p[x])
                q.push(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dis[i] + 1);
    }
    cout << ans;
    return 0;
}