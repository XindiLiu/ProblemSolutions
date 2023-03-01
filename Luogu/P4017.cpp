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
vll pathstart;
vi startcount;
vi endcount;
const ll mod = 80112002;
ll dp(int a) {
    if (startcount[a] == 0) { // end of path
        pathstart[a] = 1;
    }
    else if (pathstart[a] == 0) { // if not computed
        for (int i = 0; i < listsz[a]; i++) {
            int next = adjlist[a][i];
            pathstart[a] += dp(next);
            pathstart[a] %= mod;
        }
    }
    return pathstart[a];
};
int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    listsz = vi(n + 1, 0);
    vi* av = new vi(m);
    vi* bv = new vi(m);
    startcount = vi(n + 1, 0); // number of edges start with i
    endcount = vi(n + 1, 0); // number of edges end with i
    // adjlist = vii(n + 1, vi(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> (*av)[i] >> (*bv)[i];
        listsz[(*av)[i]]++;
        startcount[(*av)[i]]++;
        endcount[(*bv)[i]]++;
        // adjlist[a][listsz[a]++] = b;
    }

    adjlist = vii(n + 1);
    for (int i = 1; i <= n; i++) {
        adjlist[i] = vi(listsz[i]);
    }
    listsz = vi(n + 1, 0);
    for (int i = 0; i < m; i++) {
        adjlist[(*av)[i]][listsz[(*av)[i]]++] = (*bv)[i];
    }
    delete av;
    delete bv;

    pathstart = vll(n + 1, (ll)0); // number of path start with i
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (endcount[i] == 0) {
            ans += dp(i);
            ans %= mod;
        }
    }
    cout << ans;
    return 0;
}