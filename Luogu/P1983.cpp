#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
int n, m;
vi level;
vi leveltrain;
vi ingrad, outgrad;
vvi outstt;
vvi stops;
int dptrain(int tr);
int dp(int stt);

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    ingrad = vi(n + 1, 0);
    outgrad = vi(n + 1, 0);

    stops = vvi(m);
    vvi nostops(m);

    outstt = vvi(n + 1, vi(m, -1));
    for (int i = 0; i < m; i++) {
        int sz;
        cin >> sz;
        stops[i] = vi(sz);
        nostops[i] = vi(n - sz);
        vi enhot = vi(n + 1, 0);
        for (int j = 0; j < sz; j++) {
            cin >> stops[i][j];
        }
        if (stops[i][sz - 1] - stops[i][0] + 1 == sz) {
            continue;
        }

        for (int j = 0; j < sz; j++) {
            enhot[stops[i][j]] = 1;
            ingrad[stops[i][j]]++;
        }
        int pos = 0;
        for (int j = stops[i][0]; j <= stops[i][sz - 1]; j++) {
            if (enhot[j] == 0) {
                nostops[i][pos++] = j;
                outstt[j][outgrad[j]] = i;
                outgrad[j]++;
            }
        }
    }
    level = vi(n + 1, 0);
    leveltrain = vi(m, 0);
    int maxlevel = 1;
    for (int i = 1; i <= n; i++) {
        if (ingrad[i] == 0) {
            maxlevel = max(maxlevel, dp(i));
        }
    }
    cout << maxlevel;
    return 0;
}
int dp(int stt) {
    if (level[stt] > 0) {
        return level[stt];
    }
    if (outgrad[stt] == 0) {
        level[stt] = 1;
        return level[stt];
    }
    int maxlevel = 0;
    for (int i = 0; i < outgrad[stt]; i++) {
        maxlevel = max(maxlevel, dptrain(outstt[stt][i]));
    }
    level[stt] = maxlevel + 1;
    return level[stt];
}
int dptrain(int tr) {
    if (leveltrain[tr] > 0) {
        return leveltrain[tr];
    }

    int maxlevel = 0;
    for (int i = 0; i < stops[tr].size(); i++) {
        maxlevel = max(maxlevel, dp(stops[tr][i]));
    }
    leveltrain[tr] = maxlevel;
    return leveltrain[tr];
}