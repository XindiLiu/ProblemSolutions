#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<vector<int>*> v_i;
typedef vector<ll> vll;
typedef vector<string> vs;
// typedef priority_queue<int, vi, greater<int>> pq;
typedef queue<int> pq;
vi novisit;
vi listsz;
vii adjlist;
vii weight;
vll pathfrom; // max length from i to n
int n;
ll dp(int a) {
    if (a == n) {
        pathfrom[a] = 0;
        return 0;
    }
    if (pathfrom[a] == INT64_MIN) { // if not computed
        for (int i = 0; i < listsz[a]; i++) {
            int next = adjlist[a][i];
            ll ab = dp(next);
            if (ab != INT64_MIN)
                pathfrom[a] = max(ab + (ll)weight[a][i], pathfrom[a]);
        }
    }
    return pathfrom[a];
};
int main() {
    ios_base::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    listsz = vi(n + 1, 0);
    vi* av = new vi(m);
    vi* bv = new vi(m);
    vi* cv = new vi(m);

    // adjlist = vii(n + 1, vi(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> (*av)[i] >> (*bv)[i] >> (*cv)[i];
        listsz[(*av)[i]]++;
    }

    adjlist = vii(n + 1);
    weight = vii(n + 1);
    for (int i = 1; i <= n; i++) {
        adjlist[i] = vi(listsz[i]);
        weight[i] = vi(listsz[i]);
    }
    listsz = vi(n + 1, 0);
    for (int i = 0; i < m; i++) {
        weight[(*av)[i]][listsz[(*av)[i]]] = (*cv)[i];
        adjlist[(*av)[i]][listsz[(*av)[i]]++] = (*bv)[i];
    }
    delete av;
    delete bv;
    delete cv;
    pathfrom = vll(n + 1, INT64_MIN);
    int ans = dp(1);
    if (pathfrom[n] != 0) {
        cout << -1;
    }
    else
        cout << ans;
    return 0;
}