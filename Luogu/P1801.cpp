#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false);
    // pq maxheap, minheap;
    // all in maxheap are less than all in minheap
    auto minheap = priority_queue<int, vi, greater<int>>(); // the i least elements
    auto maxheap = priority_queue<int, vi, less<int>>(); // the rest
    int n, m;
    cin >> m >> n;
    vi add(m);
    vi get(n);
    for (int i = 0; i < m; i++) {
        cin >> add[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> get[i];
    }
    int i = 0;
    // int i = 0;
    for (int j = 0; j < m; j++) {
        if (i == 0 || j == 0 || add[j] >= minheap.top()) {
            minheap.push(add[j]);
        }
        else { // if less, 
            maxheap.push(add[j]); // push in maxehap
            int a = maxheap.top(); // move greatest in maxheap to top of minheap
            maxheap.pop();
            minheap.push(a);
        }

        while (i < n && get[i] == j + 1) {
            int out = minheap.top();
            minheap.pop();
            maxheap.push(out);
            cout << out << endl;
            i++;
            // i++;
        }
        if (i >= n) break;
    }

    return 0;
}
