#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main() {
    int n, m, s = 0;
    int in;
    scanf("%d%d", &n, &m);
    vector<vector<bool>> en(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &in);
            en[i][j] = in;
            if (!s && en[i][j])s = 1;
        }
    }
    int mnm = min(n, m);
    vector<vector<vector<bool>>> f(mnm + 1, vector<vector<bool>>(n, vector<bool>(m, 0)));
    f[1] = en;
    for (int k = 2; k <= mnm; k++) {
        for (int i = 0; i + k - 1 < n; i++) {
            for (int j = 0; j + k - 1 < m; j++) {
                f[k][i][j] = f[k - 1][i][j] && f[k - 1][i + 1][j] && f[k - 1][i][j + 1] && f[k - 1][i + 1][j + 1];
                if (f[k][i][j] && s < k)s = k;
            }
        }
    }
    printf("%d", s);
    return 0;
}