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

vector<list<int>> fr;
vi dfn;
vi low;
vi cc;
vi in;
vi cs;
int df;
int cn;
stack<int> stac;
void tarjan(int i) {
    low[i] = dfn[i] = ++df;
    in[i] = 1;
    stac.push(i);
    for (int v : fr[i]) {
        if (!in[v]) { // v not visited
            tarjan(v);
            low[i] = min(low[v], low[i]);
        }
        else if (in[v] == 1) {// visited, still in stack.
            low[i] = min(low[i], dfn[v]);
        }
    }
    if (low[i] == dfn[i]) {
        cn++;
        cs[cn] = 0;
        while (stac.top() != i) {
            cs[cn]++;
            cc[stac.top()] = cn;
            in[stac.top()] = 2;
            stac.pop();

        }
        cs[cn]++;
        cc[stac.top()] = cn;
        in[stac.top()] = 2;
        stac.pop();
    }
}
vi vis;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    fr = vector<list<int>>(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        fr[b].push_back(a);
    }

    dfn = vi(n + 1, 0);
    low = vi(n + 1, INT_MAX);
    cc = vi(n + 1, 0);
    in = vi(n + 1, 0);
    cs = vi(n + 1, 0);
    df = 0;
    cn = 0;
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) { tarjan(i); }
    }
    // auto from = vector<list<int>>(cn + 1);
    //vvi mx = vvi(cn + 1, vi(cn + 1, 0));
    vi ingrad(cn + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j : fr[i]) {
            if (cc[i] != cc[j]) {
                ingrad[cc[j]]++;
                // from[i].push_back(j);
                //mx[cc[i]][cc[j]] = 1;
            }
        }
    }
    int in0 = 0;
    int ans = 0;
    for (int i = 1; i <= cn; ++i) {
        if (!ingrad[i]) {
            in0++;
            ans = cs[i];
        }
    }
    ans = in0 == 1 ? ans : 0;
    cout << ans;
    return 0;
}