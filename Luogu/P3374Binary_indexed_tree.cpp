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
    binary_indexed_tree<ll> bit = binary_indexed_tree<ll>(a);
    for (int i = 1; i <= m; ++i) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            bit.add(x, y);
        }
        else if (op == 2) {
            cout << bit.range_sum(x, y) << endl;
        }
    }
    return 0;
}