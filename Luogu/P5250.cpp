#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    set<int> s = set<int>();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int o, l;
        cin >> o >> l;
        if (o == 1) {
            if (!s.insert(l).second) cout << "Already Exist" << endl;
        }
        else {
            if (s.count(l) > 0) {
                cout << l << endl;
                s.erase(l);
            }
            else if (s.empty()) {
                cout << "Empty" << endl;
            }
            else {
                auto it = s.upper_bound(l);
                int ans;
                if (it == s.begin()) { // no shorter than l
                    ans = *it;
                }
                else if (it == s.end()) { // no longer than l
                    ans = *(--s.end());
                }
                else {
                    int longer = *it;
                    int shorter = *(--it);
                    ans = (abs(longer - l) < abs(l - shorter)) ? longer : shorter;
                }
                cout << ans << endl;
                s.erase(ans);
            }
        }
    }

    return 0;
}
