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

int main() {
    ios_base::sync_with_stdio(false);
    // first: function number, second: function value
    auto comp = [](pii& a, pii& b) { return a.second > b.second; };
    auto minheap = priority_queue<pii, vector<pii>, decltype(comp)> (comp);
    int n, m;
    cin >> n;
    a = vi(n);
    b = vi(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vi xf(n, 0);

    vll ans(n);
    for (int i = 0; i < n; i++) { // put in all f(x)=1
        minheap.push(make_pair(i, a[i] + b[xf[i]]));
        xf[i]++;
    }
    for (int i = 0; i < n; i++) { // put in all f(x)=1
        int ftop = minheap.top().first;
        ans[i] = minheap.top().second;
        minheap.pop();
        minheap.push(make_pair(ftop, a[ftop] + b[xf[ftop]]));
        xf[ftop]++;
    }
    cout << ans[0];
    for_each(ans.begin() + 1, ans.end(), [](int a) {cout << ' ' << a;});
    return 0;
}
