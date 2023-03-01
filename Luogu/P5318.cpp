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
void dfs (int node) {
    if (node == 1) {
        cout << node;
    }
    else {
        cout << ' ' << node;
    }
    novisit[node] = 0;
    for (int i = 0; i < listsz[node]; i++) {
        int next = adjlist[node][i];
        if (novisit[next]) {
            dfs(next);
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
        cin >> (*av)[i] >> (*bv)[i];
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
    dfs (1);
    cout << endl;
    novisit = vi(n + 1, 1);
    // bfs(1);
    // return 0;
    pq q = pq();
    q.push(1);

    while (!q.empty()) {
        pq q1 = pq();
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == 1) {
                cout << node;
                novisit[1] = 0;
            }
            else {
                cout << ' ' << node;
            }

            for (int i = 0; i < listsz[node]; i++) {
                int next = adjlist[node][i];
                if (novisit[next]) {
                    q1.push(next);
                    novisit[next] = 0;
                    //  cout << ' ' << next;
                }
            }
        }
        q = q1;
    }
    return 0;
}