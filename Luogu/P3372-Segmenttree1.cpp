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
class segment_tree {
    int n;
    vector<T> arr;
    vector<T> tree;
    vector<pii> range;
    function<T (T, T)> operation;
    vector<T> add; // addition lazy tag
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
        else if (add[p] != 0) {
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

    /*
        [l,r] updated interval.
        [a,b] the interval of the node.
    */
    void add_segment_recurs(int term, int a, int b, int p) {
        if (a >= l && b <= r) { // [a,b] in [l,r], set lazy
            if (a == b) {
                tree[p] += term;
            }
            else {
                tree[p] += (b - a + 1) * term;
                add[p] += term;
            }
            return;
        }
        if (add[p] != 0) {
            pushdown(a, b, p);
        }

        int mid = a + ((b - a) >> 1);
        if (l <= mid) { // update left
            add_segment_recurs(term, a, mid, p * 2);
            // tree[p] += (min(mid, r) - max(l, a) + 1) * term;
        }
        if (r > mid) { // update right
            add_segment_recurs(term, mid + 1, b, p * 2 + 1);
            // tree[p] += (min(r, b) - max(mid, l - 1)) * term;
        }
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    void pushdown(int a, int b, int p) {
        T term = add[p];
        // tree[p] += term * (b - a + 1);
        int mid = a + ((b - a) >> 1);
        update(a, mid, p * 2, term);
        update(mid + 1, b, p * 2 + 1, term);
        add[p] = 0;
    }

    void update(int a, int b, int p, T term) {
        tree[p] += (b - a + 1) * term;
        add[p] += term;
    }

public:
    segment_tree(vector<T>& a, function<T (T, T)> op) {
        arr = a;
        n = a.size();
        operation = op;
        tree = vector<T>(pow(2, ceil(log2(n)) + 1));
        add = vector<T>(pow(2, ceil(log2(n)) + 1));
        build(1, n, 1);
    }

    T search(int l, int r) {
        this->l = l;
        this->r = r;
        return sum_recurs(1, n, 1);
    }

    void add_segment(int l, int r, int term) {
        this->l = l;
        this->r = r;
        return add_segment_recurs(term, 1, n, 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vll a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    segment_tree<ll> segmentree = segment_tree<ll>(a, [](ll a, ll b) {return a + b;});
    rep(i, 0, m) {
        int command;
        cin >> command;
        if (command == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            segmentree.add_segment(x, y, k);
        }
        else if (command == 2) {
            int x, y;
            cin >> x >> y;
            ll sum = segmentree.search(x, y);
            cout << sum << endl;
        }

    }
    return 0;
}
