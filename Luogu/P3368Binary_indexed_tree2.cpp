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
template <class T>
class binary_indexed_tree {
    vector<T> a;
    vector<T> c;
    int n;
    inline int lowbit(int x) { return x & (-x); }
    inline int parent(int x) { return x + lowbit(x); }
    T prefix(int x) {
        T sum = 0;
        T i = x;
        while (i > 0) {
            sum += c[i];
            i -= lowbit(i);
        }
        return sum;
    }
public:
    binary_indexed_tree(vector<T>& a1) {
        a = a1;
        n = a.size() - 1;
        c = vector<T>(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            c[i] += a[i];
            int j = parent(i);
            if (j <= n) { c[j] += c[i]; }
        }
    }

    T range_sum(int l, int r) {
        if (l == r) {
            return a[l];
        }
        else if (l == 1) {
            return prefix(r);
        }
        else {
            return prefix(r) - prefix(l - 1);
        }
    }

    void add(int i, T value) {
        a[i] += value;
        int j = i;
        while (j <= n) {
            c[j] += value;
            j = parent(j);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vll a = vll(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // let a be the prefix length of an array b
    vll b = vll(n + 1);
    b[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        b[i] = a[i] - a[i - 1];
    }
    binary_indexed_tree<ll> bit = binary_indexed_tree<ll>(b);
    for (int i = 1; i <= m; ++i) {
        int op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            bit.add(x, k);
            if (y < n)bit.add(y + 1, -k);
        }
        else if (op == 2) {
            cin >> x;
            cout << bit.range_sum(1, x) << endl;
        }
    }
    return 0;
}