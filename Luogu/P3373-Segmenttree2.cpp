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
    function<T(T, T)> operation;
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
        tree[p] = operation(tree[p * 2], tree[p * 2 + 1]) % mod;
    }

    T sum_recurs(int a, int b, int p) {
        if (a >= l && b <= r) {
            return tree[p] % mod;
        }
        else if (add[p] != 0 || mul[p] != 1) {
            pushdown(a, b, p);
        }

        int mid = a + ((b - a) >> 1);
        T result;
        if (l <= mid && r > mid) {
            result = operation(sum_recurs(a, mid, p * 2), sum_recurs(mid + 1, b, p * 2 + 1)) % mod;
        }
        else if (l > mid) {
            result = sum_recurs(mid + 1, b, p * 2 + 1) % mod;
        }
        else if (r <= mid) {
            result = sum_recurs(a, mid, p * 2) % mod;
        }
        return result % mod;
    }

    /*
        [l,r] updated interval.
        [a,b] the interval of the node.
    */
    void add_segment_recurs(T term, int a, int b, int p) {
        if (a >= l && b <= r) { // [a,b] in [l,r], set lazy
            if (a == b) {
                tree[p] = (tree[p] + term) % mod;
            }
            else {
                update(a, b, p, term, (T)1);
                // tree[p] += (b - a + 1) * term;
                // add[p] += term;
            }
            return;
        }
        if (add[p] != 0 || mul[p] != 1) {
            pushdown(a, b, p);
        }

        int mid = a + ((b - a) >> 1);
        if (l <= mid) { // update left
            add_segment_recurs(term, a, mid, p * 2);
        }
        if (r > mid) { // update right
            add_segment_recurs(term, mid + 1, b, p * 2 + 1);
        }
        tree[p] = operation(tree[p * 2], tree[p * 2 + 1]) % mod;
    }

    void mul_segment_recurs(T fact, int a, int b, int p) {
        if (a >= l && b <= r) { // [a,b] in [l,r], set lazy
            if (a == b) {
                tree[p] = (tree[p] * fact) % mod;
            }
            else {
                update(a, b, p, (T)0, fact);
                // tree[p] *= fact;
                // add[p] *= fact;
                // mul[p] *= fact;
            }
            return;
        }
        if (add[p] != 0 || mul[p] != 1) {
            pushdown(a, b, p);
        }

        int mid = a + ((b - a) >> 1);
        if (l <= mid) { // update left
            mul_segment_recurs(fact, a, mid, p * 2);
        }
        if (r > mid) { // update right
            mul_segment_recurs(fact, mid + 1, b, p * 2 + 1);
        }
        tree[p] = operation(tree[p * 2], tree[p * 2 + 1]) % mod;
    }

    void pushdown(int a, int b, int p) {
        int mid = a + ((b - a) >> 1);
        update(a, mid, p * 2, add[p], mul[p]);
        update(mid + 1, b, p * 2 + 1, add[p], mul[p]);
        add[p] = 0;
        mul[p] = 1;
    }

    void update(int a, int b, int p, T term, T fact) {
        tree[p] = ((tree[p] * fact) % mod + (b - a + 1) * term) % mod;
        add[p] = (add[p] * fact + term) % mod;
        mul[p] = (mul[p] * fact) % mod;
    }

public:
    segment_tree(vector<T>& a, function<T(T, T)> op) {
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

    void add_segment(int l, int r, T term) {
        this->l = l;
        this->r = r;
        add_segment_recurs(term, 1, n, 1);
    }

    void mul_segment(int l, int r, T fact) {
        this->l = l;
        this->r = r;
        mul_segment_recurs(fact, 1, n, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m >> mod;
    vll a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    segment_tree<ll> segmentree = segment_tree<ll>(a, [] (ll a, ll b) {return a + b; });
    rep(i, 0, m) {
        int command;
        cin >> command;
        if (command == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            segmentree.mul_segment(x, y, k);
        }
        else if (command == 2) {
            int x, y, k;
            cin >> x >> y >> k;
            segmentree.add_segment(x, y, k);
        }
        else if (command == 3) {
            int x, y;
            cin >> x >> y;
            ll sum = segmentree.search(x, y);
            cout << sum << endl;
        }

    }
    return 0;
}
