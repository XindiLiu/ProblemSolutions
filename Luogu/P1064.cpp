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
struct item {
    int w;
    int v;
    int g;
    item operator+(const item& b) {
        return item({w + b.w,v + b.v,g});
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<list<int>> group(n + 1);
    vector<item> it(n + 1);
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        it[i] = item({a, a * b ,c});
        if (c != 0) {
            group[c].push_back(i);
        }

    }
    vi dp(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (it[i].g != 0) {
            continue;
        }
        else if (group[i].size() == 0) {
            for (int w = m; w >= 0; --w) {
                if (w >= it[i].w) {
                    dp[w] = max(dp[w], dp[w - it[i].w] + it[i].v);
                }
            }
        }
        else {

            vi b = vi(group[i].begin(), group[i].end());
            vector<item> tmp;
            if (group[i].size() == 1) {
                tmp = vector<item>({it[i],it[i] + it[b[0]]});
            }
            else if (group[i].size() == 2) {
                tmp = vector<item>({it[i], it[i] + it[b[0]],it[i] + it[b[1]],it[i] + it[b[0]] + it[b[1]]});
            }
            for (int w = m; w >= 0; --w) {
                for (item itm : tmp) {
                    if (w >= itm.w)
                        dp[w] = max(dp[w], dp[w - itm.w] + itm.v);
                }
            }

        }
    }
    cout << dp[m];

    return 0;
}