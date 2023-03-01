#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unordered_multimap<string, int> umsi;
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    umsi a = umsi();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            string s;
            cin >> s;
            a.insert(make_pair(s, i));
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {

        string s;
        cin >> s;
        auto ab = a.equal_range(s);
        int sc = a.count(s);
        vi c = vi(sc);
        if (sc == 0) {
            cout << endl;
            continue;
        }
        int iii = 0;
        for (auto it = ab.first; it != ab.second; it++) {
            c[iii++] = (it->second) + 1;
        }

        sort(c.begin(), c.begin() + sc);
        sc = unique(c.begin(), c.begin() + sc) - c.begin();
        int ii = 0;
        cout << c[ii++];
        for (; ii < sc; ii++) {
            cout << ' ';
            cout << c[ii];
        }
        cout << endl;

    }

    return 0;
}
