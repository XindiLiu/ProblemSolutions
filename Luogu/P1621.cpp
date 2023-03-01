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
    int a, b, p;
    cin >> a >> b >> p;
    init(b);
    vi prime = vi(b + 1, 1);

    for (int i = 2; i <= b; i++) {
        if (prime[i]) {
            int root = 0;
            for (int j = 2 * i; j <= b; j += i) {
                prime[j] = 0;


                if (i >= p && j >= a) {
                    if (root == 0) {
                        root = j;
                        parent[i] = j;
                        sz[j]++;
                    }
                    else
                        setunion(j, i);
                }
            }
        }
    }
    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (find(i) == i)ans++;
    }

    cout << ans;

    return 0;
}
