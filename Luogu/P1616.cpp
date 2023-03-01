#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, m;
    cin >> t >> m;
    vector<int> varde(m);
    vector<int> tid(m);
    vector<int> ks(t + 1, 0);
    int x;
    for (int i = 0; i < m; i++)scanf("%d%d", &tid[i], &varde[i]);
    for (int i = 0; i < m; i++) {
        for (int j = tid[i]; j <= t; j++) {

            if ((x = ks[j - tid[i]] + varde[i]) > ks[j])ks[j] = x;
        }
    }
    cout << ks[t];
    return 0;
}