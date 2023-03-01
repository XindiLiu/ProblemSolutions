#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> hs;
vector<vector<int>> ls;
int main() {
    int n, mins = 10000000, maxs = 0;
    cin >> n;
    vector<int> sd(n);
    for (int i = 0; i < n; i++) { cin >> sd[i]; }
    hs.assign(n, vector<int>(n, 0));
    ls.assign(n, vector<int>(n, 0));
    vector<int> sums(n + 1);
    sums[0] = 0;
    for (int i = 0; i < n; i++) { sums[i + 1] = sums[i] + sd[i]; }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int k = j;
            int jin = (j + i) % n;
            ls[j][jin] = 100000000;
            while (k < j + i) {
                hs[j][jin] = max(hs[j][jin], (hs[j][k % n] + hs[(k + 1) % n][jin]));
                ls[j][jin] = min(ls[j][jin], (ls[j][k % n] + ls[(k + 1) % n][jin]));
                k++;
            }
            hs[j][jin] += (j + i < n) ? (sums[j + i + 1] - sums[j]) : (sums[n] - sums[j] + sums[jin + 1]);
            ls[j][jin] += (j + i < n) ? (sums[j + i + 1] - sums[j]) : (sums[n] - sums[j] + sums[jin + 1]);
        }
    }
    int i = n - 1;
    for (int j = 0; j < n; j++) {
        int k = j;
        int jin = (j + i) % n;
        ls[j][jin] = 100000000;
        while (k < j + i) {

            hs[j][jin] = max(hs[j][jin], (hs[j][k % n] + hs[(k + 1) % n][jin]));
            ls[j][jin] = min(ls[j][jin], (ls[j][k % n] + ls[(k + 1) % n][jin]));
            k++;

        }
        hs[j][jin] += (j + i < n) ? (sums[j + i + 1] - sums[j]) : (sums[n] - sums[j] + sums[jin + 1]);
        ls[j][jin] += (j + i < n) ? (sums[j + i + 1] - sums[j]) : (sums[n] - sums[j] + sums[jin + 1]);

        maxs = max(maxs, hs[j][jin]);
        mins = min(mins, ls[j][jin]);
    }
    cout << mins << endl << maxs;
    return 0;
}