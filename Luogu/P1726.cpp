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
    int u, v, w;
};
bool edcp(const edge& a, const edge& b) { return a.w < b.w; };

int n, m;

vector<list<int>> from;

vi dfn;
vi low;
vi vis;
vi cc;
vi cw;
int cn;
stack<int> stac;
int dfncnt;

void tarjan(int x) {
    stac.push(x);
    dfn[x] = ++dfncnt;
    low[x] = dfn[x];
    vis[x] = 1;
    for (int i : from[x]) {
        if (!vis[i]) {
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if (vis[i] == 1) {
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (dfn[x] == low[x]) {
        cn++;
        while (stac.top() != x) {
            cc[stac.top()] = cn;
            cw[cn] ++;
            vis[stac.top()] = 2;
            stac.pop();
        }
        cc[stac.top()] = cn;
        cw[cn] ++;
        vis[stac.top()] = 2;
        stac.pop();
    }
}
vi dp;

vector<list<int>> fr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int inm;
    cin >> n >> inm;
    m = inm;

    from = vector<list<int>>(n + 1);

    for (int i = 0; i < inm; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        from[x].push_back(y);
        if (t == 2) {
            from[y].push_back(x);
            m++;
        }
    }

    dfn = vi(n + 1, 0);
    low = vi(n + 1, INT_MAX);
    vis = vi(n + 1, 0);
    cc = vi(n + 1, 0);
    cw = vi(n + 1, 0);
    cn = 0;
    dfncnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    int maxcc = 0;
    int maxcs = 0;
    for (int i = 1; i <= n; ++i) {
        if (cw[cc[i]] > maxcs) {
            maxcc = cc[i];
            maxcs = cw[cc[i]];
        }
    }
    cout << maxcs << endl;
    for (int i = 1; i <= n; ++i) {
        if (cc[i] == maxcc) {
            cout << i << " ";
        }

    }
    return 0;
}