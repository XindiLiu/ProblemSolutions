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
typedef map<int, int> mii;
typedef vector<bool> vb;

vb damagestr;
vi tree;
vb lazy;
void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = damagestr[l - 1];
        return;
    }
    int mid = (r + l) >> 1;
    build(p << 1, l, mid);
    build((p << 1) + 1, mid + 1, r);
    tree[p] = tree[p << 1] + tree[(p << 1) + 1];
};

void pushdown(int p, int l, int r) {
    int mid = (r + l) >> 1;
    tree[p << 1] = (mid - l + 1) - tree[p << 1];
    tree[(p << 1) + 1] = (r - mid) - tree[(p << 1) + 1];
    lazy[p << 1] = !lazy[p << 1];
    lazy[(p << 1) + 1] = !lazy[(p << 1) + 1];
    lazy[p] = 0;
};

int damage(int p, int l, int r, int s, int e) {
    if (l >= s && r <= e) {
        return tree[p];
    }
    else if (lazy[p]) {
        pushdown(p, l, r);
    }
    int mid = (r + l) >> 1;
    int result = 0;
    if (s <= mid) {
        result += damage(p << 1, l, mid, s, e);
    }
    if (e > mid) {
        result += damage((p << 1) + 1, mid + 1, r, s, e);
    }
    return result;
};


void modify(int p, int l, int r, int s, int e) {
    if (l >= s && r <= e) {
        tree[p] = (r - l + 1) - tree[p];
        lazy[p] = !lazy[p];
        return;
    }
    else if (lazy[p]) {
        pushdown(p, l, r);
    }

    int mid = (r + l) >> 1;

    if (s <= mid) {
        modify(p << 1, l, mid, s, e);
    }
    if (e > mid) {
        modify((p << 1) + 1, mid + 1, r, s, e);
    }
    tree[p] = tree[p << 1] + tree[(p << 1) + 1];
};


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s = string(n, 0);
    cin >> s;
    damagestr = vb(n);
    transform(all(s), damagestr.begin(), [] (char c) {return c - '0'; });
    int maxnode = pow(2, ceil(log2(n)) + 1) + 1;
    tree = vi(maxnode);
    lazy = vb(maxnode, 0);
    build(1, 1, n);

    rep(i, 0, m) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op) {
            cout << damage(1, 1, n, l, r) << endl;
        }
        else {
            modify(1, 1, n, l, r);
        }
    }
    return 0;
}