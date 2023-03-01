#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<string> vs;
typedef priority_queue<int> pq;
vi  a;
vi  b;
vi  c;
vll xpow2;
ll func(int x, int f) {
    if (xpow2[x] == 0) {
        xpow2[x] = x * x;
    }
    return (ll)a[f] * xpow2[x] + (ll)b[f] * (ll)x + (ll)c[f];
};

int main() {
    ios_base::sync_with_stdio(false);
    // first: function number, second: function value
    auto comp = [](pii& a, pii& b) { return a.second > b.second; };
    auto minheap = priority_queue<pii, vector<pii>, decltype(comp)> (comp);
    int n, m;
    cin >> n >> m;
    a = vi(n);
    b = vi(n);
    c = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vi xf(n, 1);
    xpow2 = vll(m + 1, 0);
    vll ans(m);
    for (int i = 0; i < n; i++) { // put in all f(x)=1
        minheap.push(make_pair(i, func(xf[i], i)));
        xf[i]++;
    }
    for (int i = 0; i < m; i++) { // put in all f(x)=1
        int ftop = minheap.top().first;
        ans[i] = minheap.top().second;
        minheap.pop();
        minheap.push(make_pair(ftop, func(xf[ftop], ftop)));
        xf[ftop]++;
    }
    cout << ans[0];
    for_each(ans.begin() + 1, ans.end(), [](int a) {cout << ' ' << a;});
    return 0;
}
