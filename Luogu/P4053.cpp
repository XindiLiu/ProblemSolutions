#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vp;
typedef vector<vector<ll>> vvll;
typedef vector<string> vs;
typedef priority_queue<int> pq;
vp  t;


int main() {
    ios_base::sync_with_stdio(false);
    // first: function number, second: function value
    auto comp = [](pii& a, pii& b) { return a.first < b.first; };
    auto minheap = priority_queue<pii, vector<pii>, decltype(comp)> (comp);
    int n, m;
    cin >> n;
    t = vp(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second;
    }

    sort(t.begin(), t.end(), [](pii a, pii b) {return (a.second == b.second) ? (a.first < b.first) : (a.second < b.second);});

    ll sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum + t[i].first < t[i].second) {
            ans++;
            sum += t[i].first;
            minheap.push(t[i]);
        }
        else {
            minheap.push(t[i]);
            sum += t[i].first - minheap.top().first;
            minheap.pop();
        }
    }
    cout << ans;
    return 0;
}
