#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
    int svar = 0;
    for (int i = 1; i <= n; i++) {
        nth_element(a[i].begin(), a[i].begin() + 1, a[i].end(), greater<int>());
        svar = max(svar, a[i][1]);
    }
    cout << 1 << endl << svar;
    return 0;
}