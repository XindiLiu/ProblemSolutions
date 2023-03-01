#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
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
bool check(int x, int y) {
    int xp = find(x);
    int yp = find(y);
    return xp == yp;
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
    int t;
    cin >> t;
    for (int iiii = 0; iiii < t; iiii++) {
        int n;
        cin >> n;

        vi ineql = vi(n + 1);
        vi ineqr = vi(n + 1);
        vi ineqe = vi(n + 1);
        mii m = mii();
        int msize = 1;
        for (int i = 0; i < n; i++) {
            int a, b, e;
            cin >> a >> b >> e;
            ineql[i] = a;
            ineqr[i] = b;
            ineqe[i] = e;
            if (m.find(a) == m.end()) m[a] = msize++;
            if (m.find(b) == m.end()) m[b] = msize++;
        }
        init(msize);
        for (int i = 0; i < n; i++) {
            if (ineqe[i] == 1) {
                setunion(m[ineql[i]], m[ineqr[i]]);
            }

        }

        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (ineqe[i] == 0)
                if (check(m[ineql[i]], m[ineqr[i]])) {
                    ans = "NO";
                    break;
                }
        }
        cout << ans << endl;
    }
    return 0;
}
