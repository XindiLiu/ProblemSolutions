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
    int n;
    cin >> n;
    vi  a(n);
    int k = (n) / 2;
    cin >> a[0];
    maxheap.push(a[0]);
    cout << a[0] << endl;
    for (int i = 1; i < n - 1; i += 2) {
        int a1, a2;
        cin >> a1 >> a2;
        if (a1 > a2) {
            swap(a1, a2);
        }
        int mid = maxheap.top();
        if (a1 <= mid && a2 >= mid) {
            maxheap.push(a1);
            minheap.push(a2);
        }
        else if (a1 >= mid && a2 > mid) {
            minheap.push(a1);
            minheap.push(a2);
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if (a1 < mid && a2 <= mid) {
            maxheap.push(a1);
            maxheap.push(a2);
            minheap.push(maxheap.top());
            maxheap.pop();
        }

        mid = maxheap.top();
        cout << mid << endl;


    }

    return 0;
}
