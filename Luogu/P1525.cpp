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
vi setsize;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    }
};

void setunion(int x, int y) {
    if (parent[x] == parent[y]) {
        return;
    }

    int xp = find(x);
    int yp = find(y);
    if (setsize[xp] > setsize[yp]) {
        parent[yp] = xp;
        setsize[xp] += setsize[yp];
    }
    else {
        parent[xp] = yp;
        setsize[yp] += setsize[xp];
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vi a = vi(m);
    vi b = vi(m);
    vi c = vi(m);
    vi crank = vi(m);
    parent = vi (n * 2 + 1);
    setsize = vi(n * 2 + 1, 1);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        crank[i] = i;
    }
    sort(crank.begin(), crank.end(), [&](int c1, int c2) {return c[c1] > c[c2];});

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        parent[i + n] = i + n;
    }

    for (int i = 0; i < m; i++) {
        int ci = crank[i];
        if (find(a[ci]) == find(b[ci]) || find(a[ci] + n) == find(b[ci] + n)) {
            cout << c[ci];
            return 0;
        }
        setunion(a[ci], b[ci] + n);
        setunion(a[ci] + n, b[ci]);
    }

    cout << 0;
    return 0;
}
