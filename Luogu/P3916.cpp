#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
// typedef priority_queue<int, vi, greater<int>> pq;
typedef queue<int> pq;
vi novisit;
vi listsz;
vii adjlist;
vi maxreachable;
void dfs (int node, int source) {
    novisit[node] = 0;
    maxreachable[node] = source;
    for (int i = 0; i < listsz[node]; i++) {
        int next = adjlist[node][i];
        if (novisit[next]) {
            dfs(next, source);
        }
    }
};

void bfs (int node) {
    if (!novisit[node]) return;
    if (node == 1) {
        cout << node;
    }


    novisit[node] = 0;
    for (int i = 0; i < listsz[node]; i++) {
        int next = adjlist[node][i];
        if (novisit[next]) {
            cout << ' ' << next;
        }
    }

    for (int i = 0; i < listsz[node]; i++) {
        int next = adjlist[node][i];
        bfs(next);
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    listsz = vi(n + 1, 0);
    vi* av = new vi(m);
    vi* bv = new vi(m);
    // adjlist = vii(n + 1, vi(n, 0));
    for (int i = 0; i < m; i++) {
        cin >> (*bv)[i] >> (*av)[i];
        listsz[(*av)[i]]++;
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
    for (int i = 1; i <= n; i++) {
        sort(adjlist[i].begin(), adjlist[i].begin() + listsz[i]);
    }
    novisit = vi(n + 1, 1);
    maxreachable = vi(n + 1, 1);
    for (int i = n; i >= 0; i--) {
        if (novisit[i]) {
            dfs(i, i);
        }
    }
    cout << maxreachable[1];
    for (int i = 2; i <= n; i++) {
        cout << ' ' << maxreachable[i];
    }
    return 0;
}