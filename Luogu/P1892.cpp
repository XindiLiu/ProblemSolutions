#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi parent;
vi sz;
int find(int x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
};
void setunion(int x, int y) {
    int xp = find(x);
    int yp = find(y);
    if (xp == yp) return;
    else if (sz[xp] > sz[yp]) {
        parent[yp] = xp;
        sz[xp] += sz[yp];
    }
    else {
        parent[xp] = yp;
        sz[yp] += sz[xp];
    }
};
void init(int n) {
    parent = vi(n + 1);
    sz = vi(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

};
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    init(n);
    vector<vi> enemy = vector<vi>(n + 1, vi(n + 1, 0));
    vi numenemy = vi(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int p, q;
        char opt;
        cin >> opt >> p >> q;
        if (opt == 'F') {
            setunion(p, q);
        }
        else {
            enemy[p][numenemy[p]++] = q;
            enemy[q][numenemy[q]++] = p;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < numenemy[i]; j++) {
            setunion(enemy[i][j], enemy[i][0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            ans++;
        }
    }


    cout << ans;

    return 0;
}