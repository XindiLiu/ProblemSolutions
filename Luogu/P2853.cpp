#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
const int a = 'a';
int n, k, m;

vi cow;
vii mtx;
vi novisit;
vii adjlist;
void dfs (int node) {
    if (!novisit[node])return;
    novisit[node] = 0;
    for (int i = 0; i < adjlist[node].size(); i++) {
        int next = adjlist[node][i];
        if (novisit[next]) {
            dfs(next);
            for (int j = 1; j <= n;j++) {
                mtx[node][j] |= mtx[next][j];
            }
        }

    }
};
int main() {
    ios_base::sync_with_stdio(false);

    cin >> k >> n >> m;

    cow = vi(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        cow[c]++;
    }
    mtx = vii(n + 1, vi(n + 1, 0));
    adjlist = vii(n + 1);
    for (int i = 1; i <= n; i++) { mtx[i][i] = 1; }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!mtx[a][b]) {
            mtx[a][b] = 1;
            adjlist[a].push_back(b);
        }
    }
    novisit = vi(n + 1, 1);
    vi ansv(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (cow[i]) {
            novisit = vi(n + 1, 1);
            dfs(i);
            for (int j = 1; j <= n; j++) {
                ansv[j] &= mtx[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += ansv[i];
    }

    cout << ans;
    return 0;
}