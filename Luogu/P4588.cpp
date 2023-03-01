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
ll mod;
template <class T>
class segment_tree {
    int n;
    vector<T> arr;
    vector<T> tree;
    vector<pii> range;
    function<T (T, T)> operation;
    vector<T> add; // addition lazy tag
    vector<T> mul; // multiplication lazy tag
    int l, r;
    void build(int l, int r, int p) {
        if (l == r) {
            tree[p] = arr[l - 1];
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(l, mid, p * 2);
        build(mid + 1, r, p * 2 + 1);
        tree[p] = operation(tree[p * 2], tree[p * 2 + 1]);
    }

    T sum_recurs(int a, int b, int p) {
        if (a >= l && b <= r) {
            return tree[p];
        }
        else if (add[p] != 0 || mul[p] != 1) {
            pushdown(a, b, p);
        }

        int mid = a + ((b - a) >> 1);
        T result;
        if (l <= mid && r > mid) {
            result = operation(sum_recurs(a, mid, p * 2), sum_recurs(mid + 1, b, p * 2 + 1));
        }
        else if (l > mid) {
            result = sum_recurs(mid + 1, b, p * 2 + 1);
        }
        else if (r <= mid) {
            result = sum_recurs(a, mid, p * 2);
        }
        return result;
    }

    void divide_single_recurs(int i, int a, int b, int p) {
        if (a == i && b == i) {
            tree[p] = 1;
            return;
        }
        int mid = a + ((b - a) >> 1);
        if (i <= mid) { // update left
            divide_single_recurs(i, a, mid, p * 2);
        }
        else if (i > mid) { // update right
            divide_single_recurs(i, mid + 1, b, p * 2 + 1);
        }
        tree[p] = operation(tree[p * 2], tree[p * 2 + 1]);
    }

    /*
        [l,r] updated interval.
        [a,b] the interval of the node.
    */
    // void add_segment_recurs(T term, int a, int b, int p) {
    //     if (a >= l && b <= r) { // [a,b] in [l,r], set lazy
    //         if (a == b) {
    //             tree[p] = (tree[p] + term) % mod;
    //         }
    //         else {
    //             update(a, b, p, term, (T)1);
    //             // tree[p] += (b - a + 1) * term;
    //             // add[p] += term;
    //         }
    //         return;
    //     }
    //     if (add[p] != 0 || mul[p] != 1) {
    //         pushdown(a, b, p);
    //     }

    //     int mid = a + ((b - a) >> 1);
    //     if (l <= mid) { // update left
    //         add_segment_recurs(term, a, mid, p * 2);
    //     }
    //     if (r > mid) { // update right
    //         add_segment_recurs(term, mid + 1, b, p * 2 + 1);
    //     }
    //     tree[p] = operation(tree[p * 2], tree[p * 2 + 1]) % mod;
    // }

    // void mul_segment_recurs(T fact, int a, int b, int p) {
    //     if (a >= l && b <= r) { // [a,b] in [l,r], set lazy
    //         if (a == b) {
    //             tree[p] = (tree[p] * fact) % mod;
    //         }
    //         else {
    //             update(a, b, p, (T)0, fact);
    //             // tree[p] *= fact;
    //             // add[p] *= fact;
    //             // mul[p] *= fact;
    //         }
    //         return;
    //     }
    //     if (add[p] != 0 || mul[p] != 1) {
    //         pushdown(a, b, p);
    //     }

    //     int mid = a + ((b - a) >> 1);
    //     if (l <= mid) { // update left
    //         mul_segment_recurs(fact, a, mid, p * 2);
    //     }
    //     if (r > mid) { // update right
    //         mul_segment_recurs(fact, mid + 1, b, p * 2 + 1);
    //     }
    //     tree[p] = operation(tree[p * 2], tree[p * 2 + 1]) % mod;
    // }

    // void pushdown(int a, int b, int p) {
    //     int mid = a + ((b - a) >> 1);
    //     update(a, mid, p * 2, add[p], mul[p]);
    //     update(mid + 1, b, p * 2 + 1, add[p], mul[p]);
    //     add[p] = 0;
    //     mul[p] = 1;
// }

// void update(int a, int b, int p, T term, T fact) {
//     tree[p] = ((tree[p] * fact) % mod + (b - a + 1) * term) % mod;
//     add[p] = (add[p] * fact + term) % mod;
//     mul[p] = (mul[p] * fact) % mod;
// }

public:
    segment_tree(vector<T>& a, function<T (T, T)> op) {
        arr = a;
        n = a.size();
        operation = op;
        tree = vector<T>(pow(2, ceil(log2(n)) + 1));
        add = vector<T>(pow(2, ceil(log2(n)) + 1), 0);
        mul = vector<T>(pow(2, ceil(log2(n)) + 1), 1);
        build(1, n, 1);
    }

    T search(int l, int r) {
        this->l = l;
        this->r = r;
        ll sum = sum_recurs(1, n, 1);
        return (sum + mod) % mod;
    }

    void divide_single(int i) {
        divide_single_recurs(i, 1, n, 1);
    }
    // void add_segment(int l, int r, T term) {
    //     this->l = l;
    //     this->r = r;
    //     add_segment_recurs(term, 1, n, 1);
    // }

    // void mul_segment(int l, int r, T fact) {
    //     this->l = l;
    //     this->r = r;
    //     mul_segment_recurs(fact, 1, n, 1);
    // }

};

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(ti, 0, t) {
        int q;
        cin >> q >> mod;
        vi m(q + 1);
        vi op(q + 1);
        int n = 0;
        vll a(q); // The underlying array
        a[0] = 1;
        vi h(q + 1); // position in the array of the segmenttree
        // vi g(q + 1); // m in operation 2 -> position in the array of the segmenttree
        rep(i, 0, q) {
            cin >> op[i] >> m[i];
            if (op[i] == 1) {
                a[n + 1] = m[i];
                h[i] = n + 2;

                n++;
            }
            else {
                h[i] = h[i - 1];

            }
        }
        a.resize(n + 1);
        segment_tree<ll> segmentree = segment_tree<ll>(a, [&](ll a1, ll b1) {return (a1 * b1) % mod;});
        rep(i, 0, q) {
            ll ans = 1;
            int j = h[i];
            if (op[i] == 2) {
                int skip = h[m[i] - 1];
                segmentree.divide_single(skip);
            }
            ans = segmentree.search(1, j);
            // if (op[i] == 1) {
            //     int j = h[i];
            //     ans = segmentree.search(1, j);
            // }

            cout << ans << endl;
        }
    }

    return 0;
}
