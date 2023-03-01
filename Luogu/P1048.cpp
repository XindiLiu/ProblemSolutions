#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, m;
    cin >> t >> m;
    vector<int> varde(m);
    vector<int> tid(m);
    vector<int> ks(t + 1, 0);
    for (int i = 0; i < m; i++)cin >> tid[i] >> varde[i];
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= tid[i]; j--) {
            ks[j] = max(ks[j], ks[j - tid[i]] + varde[i]);
        }
    }
    cout << ks[t];
    return 0;
}