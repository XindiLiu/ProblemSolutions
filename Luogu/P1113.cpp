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
void dfs(int node, int source) {
    novisit[node] = 0;
    maxreachable[node] = source;
    for (int i = 0; i < listsz[node]; i++) {
        int next = adjlist[node][i];
        if (novisit[next]) {
            dfs(next, source);
        }
    }
};

void bfs(int node) {
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

    int n;
    cin >> n;
    vi time = vi(n + 1, 0);
    vi tottime = vi(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, t;
        cin >> a >> time[a];
        int p;
        int pret;
        cin >> p;
        if (p == 0) {
            tottime[a] = time[a];
            continue;
        }
        else {
            pret = 0;
        }
        while (p != 0) {
            pret = max(pret, tottime[p]);
            cin >> p;
        }
        tottime[a] = pret + time[a];
    }
    cout << *max_element(tottime.begin() + 1, tottime.end());
    return 0;
}