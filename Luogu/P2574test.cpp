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
int damage(int p, int l, int r, int s, int e) {
    int result = 0;
    for (int i = s; i <= e; ++i) {
        if (damagestr[i]) {
            result++;
        }
    }
    return result;
};
void modify(int p, int l, int r, int s, int e) {
    for (int i = s; i <= e; ++i) {
        damagestr[i] = damagestr[i] ? 0 : 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s = string(n, 0);
    cin >> s;
    damagestr = vb(n + 1);
    transform(all(s), damagestr.begin() + 1, [] (char c) {return c - '0'; });
    int maxnode = pow(2, ceil(log2(n)) + 1) + 1;

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