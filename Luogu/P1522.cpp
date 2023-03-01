#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<double> vd;
struct edge {
    int to;
    double w;
    edge(int t1, double w1) :to(t1), w(w1) {};
};
typedef vector<list<edge>> vle;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
double dist(pii a, pii b) { return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second)); }
// vector<list<int>*> chunks;
vector<list<int>> chunks;
vi p;
vi sz;
int nc;
int find(int x) {
    int a = x;
    while (p[a] != a) {
        a = p[a];
    }
    p[x] = a;
    return a;
}
void unionset(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        nc -= 1;
        if (sz[fx] > sz[fy]) {
            p[fy] = fx;
            sz[fx] += sz[fy];
            chunks[fx].splice(chunks[fx].begin(), chunks[fy]);
            // delete chunks[fy];
        }
        else {
            p[fx] = fy;
            sz[fy] += sz[fx];
            chunks[fy].splice(chunks[fy].begin(), chunks[fx]);
            // delete chunks[fx];
        }
    }
}
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    // cin >> n;
    scanf("%d", &n);

    nc = n;
    vector<pii> nodes(n);

    p = vi(n);
    chunks = vector<list<int>>(n);
    sz = vi(n, 1);
    vector<vd> f;
    f = vector<vd>(n, vd(n, INT64_MAX));
    for (int i = 0; i < n; ++i) {
        int a, b;

        scanf("%d%d", &a, &b);
        // cin >> a >> b;
        nodes[i] = make_pair(a, b);
        chunks[i].push_back(i);
        p[i] = i;
        f[i][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        // string s;
        // cin >> s;
        for (int j = 0; j < n; ++j) {
            int c;
            scanf("%1d", &c);
            if (j < i && c == 1) {
                unionset(i, j);
                double d = dist(nodes[i], nodes[j]);
                f[i][j] = d;
                f[j][i] = d;

            }
        }
    }
    auto abc = vector<list<int>>(nc);
    for (int i = 0, counter = 0; i < n; ++i) {
        if (p[i] == i) {
            abc[counter++] = chunks[i];
            // delete chunks[i];
        }
    }

    for (auto a : abc) {
        for (int k : a) {
            for (int i : a) {
                for (int j : a) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
    }

    vd far = vd(n, 0);
    vd dia = vd(nc, 0);
    for (int a = 0; a < nc; a++) {
        for (int i : abc[a]) {
            for (int j : abc[a]) {
                far[i] = max(far[i], f[i][j]);
                dia[a] = max(dia[a], f[i][j]);
            }
        }
    }
    double ans = INT64_MAX;
    for (int ai = 0; ai < nc; ++ai) {
        for (int bi = 0; bi < ai; ++bi) {
            for (int i : abc[ai]) {
                for (int j : abc[bi]) {
                    double nd = far[i] + far[j] + dist(nodes[i], nodes[j]);
                    nd = max(nd, max(dia[ai], dia[bi]));
                    ans = min(ans, nd);
                }
            }
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(6) << ans << endl;
    // cout << ans;
    return 0;
}