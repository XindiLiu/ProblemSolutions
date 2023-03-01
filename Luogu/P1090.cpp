#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
// typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> min_heap;
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    min_heap h = min_heap();
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        h.push(a);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int a1 = h.top();
        h.pop();
        int a2 = h.top();
        h.pop();
        int a12 = a1 + a2;
        ans += a12;
        h.push(a12);
    }

    cout << ans;
    return 0;
}
