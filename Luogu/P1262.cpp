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
typedef vector<list<int>> vli;
vi cost;
vli fr;
vi dfn;
vi low;
vi vis;
vi cc;
int cn;
stack<int> stac;
int dfncnt;

void tarjan(int x) {
    stac.push(x);
    dfn[x] = ++dfncnt;
    low[x] = dfn[x];
    vis[x] = 1;
    for (int i : fr[x]) {
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
            vis[stac.top()] = 2;
            stac.pop();
        }
        cc[stac.top()] = cn;
        vis[stac.top()] = 2;
        stac.pop();
    }
}
vi con;
vli from;
void sou(int a) {
    con[a] = 1;
    for (int i : from[a]) {
        if (!con[i]) {
            sou(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, l;
    cin >> n >> l;
    cost = vi(n + 1, INT_MAX);
    for (int i = 0; i < l; ++i) {
        int a, b;
        cin >> a >> b;
        cost[a] = b;
    }

    cin >> m;
    fr = vli(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        fr[a].push_back(b);
    }
    dfn = vi(n + 1, 0);
    low = vi(n + 1, 0);
    vis = vi(n + 1, 0);
    cc = vi(n + 1, 0);
    cn = 0;
    dfncnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            tarjan(i);
        }
    }
    from = vli(cn + 1);
    vi ingrad(cn + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j : fr[i]) {
            if (cc[i] != cc[j]) {
                from[cc[i]].push_back(cc[j]);
                ingrad[cc[j]]++;
            }
        }
    }
    vi nc(cn + 1, INT_MAX);
    for (int i = 1; i <= n; ++i) {
        nc[cc[i]] = min(nc[cc[i]], cost[i]);

    }

    con = vi(cn + 1, 0);
    for (int i = 1; i <= cn; ++i) {
        if (nc[i] != INT_MAX && con[i] == 0) {
            sou(i);
        }
    }
    int yes = 1;
    for (int i = 1; i <= cn; ++i) {
        if (!con[i]) {
            yes = 0;
            break;
        }
    }
    int ans = 0;
    if (yes) {
        for (int i = 1; i <= cn; ++i) {
            if (ingrad[i] == 0) {
                if (nc[i] != INT_MAX) {
                    ans += nc[i];
                }
            }
        }
        cout << "YES" << endl << ans;
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (!con[cc[i]]) {
                cout << "NO" << endl << i;
                break;
            }
        }
    }


    return 0;
}