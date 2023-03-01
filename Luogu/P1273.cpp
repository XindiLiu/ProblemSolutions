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

struct child {
    int to;
    int cost;
};

vi value;
vector<vector<int>*> fr;
vvi f;
vi cost;
vi numtv;
int n, m;
void dp(int x) {
    if (x > n - m)return;
    for (int ii = 0; ii < fr[x]->size(); ++ii) {
        int i = fr[x]->at(ii);
        if (i <= n - m) dp(i);
        // else {
        //     f[i][1] = cost[i];
        // }
        // numtv[x] += numtv[fr[x]->at(i)];
        for (int j = numtv[x] + numtv[i]; j >= 1; --j) {
            for (int k = max(j - numtv[x], 1); k <= min(j, numtv[i]); ++k) {
                f[x][j] = max(f[x][j], f[x][j - k] + f[i][k] + cost[i]);
            }

        }
        numtv[x] += numtv[i];
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    fr = vector<vector<int>*>(n + 1);
    value = vi(m);
    cost = vi(n + 1, 0);
    numtv = vi(n + 1, 0);
    f = vvi(n + 1, vi(m + 1, INT_MIN));
    for (int i = 1; i <= n - m; ++i) {
        int k;
        cin >> k;
        fr[i] = new vector<int>(k);
        for (int j = 0; j < k; ++j) {
            int a, c;
            cin >> a >> c;
            fr[i]->at(j) = a;
            cost[a] = -c;
        }
    }

    for (int i = m; i > 0; --i) {
        int v;
        cin >> v;
        // cost[n - i + 1] += v;
        // value[n - i + 1] = v;
        numtv[n - i + 1] = 1;
        f[n - i + 1][1] = v;
    }
    for (int i = 0; i <= n; ++i) {
        f[i][0] = 0;
    }
    dp(1);
    for (int i = m; i >= 0; --i) {
        if (f[1][i] >= 0) {
            cout << i;
            break;
        }
    }

    return 0;
}