#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>*> vvi;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;
// typedef vector<string> vs;
// typedef priority_queue<int> pq;
vi  a;
vi  b;
vi  c;
vi xpow2;
vvi fvalues;
int func(int x, int f) {
    if (fvalues[f]->size() <= x) {
        if (xpow2[x] == 0) {
            xpow2[x] = x * x;
        }
        int xll = x;
        fvalues[f]->push_back((int)a[f] * xpow2[x] + (int)b[f] * xll + (int)c[f]);
    }
    else if (fvalues[f]->at(x) == 0) {
        if (xpow2[x] == 0) {
            xpow2[x] = x * x;
        }
        int xll = x;
        fvalues[f]->at(x) = (int)a[f] * xpow2[x] + (int)b[f] * xll + (int)c[f];
    }

    return fvalues[f]->at(x);
};
int main() {
    ios_base::sync_with_stdio(false);
    // pq maxheap, minheap;
    // all in maxheap are less than all in minheap
    // auto minheap = priority_queue<int, vi, greater<int>>(); // the i least elements
    // auto maxheap = priority_queue<int, vi, less<int>>(); // the rest
    vi maxheap;
    int n, m;
    cin >> n >> m;
    a = vi(n);
    b = vi(n);
    c = vi(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    maxheap = vi(m);
    vi xf(n, 1);
    xpow2 = vi(m + 1, 0);
    fvalues = vvi(n);
    for (int i = 0; i < n; i++) {
        fvalues[i] = new vi(1);
    }
    int num_values = 0;

    for (int j = 0; j < m; j++) {
        int minvalue = INT_MAX;
        int minf = 0;
        for (int i = 0; i < n; i++) { // for each function
            if (func(xf[i], i) < minvalue) {
                minvalue = func(xf[i], i);
                minf = i;
            }
        }
        maxheap[j] = minvalue;
        xf[minf]++;
    }
    cout << maxheap[0];
    for_each(maxheap.begin() + 1, maxheap.end(), [](int a) {cout << ' ' << a;});

    return 0;
}
