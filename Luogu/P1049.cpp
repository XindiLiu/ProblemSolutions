#include <bits/stdc++.h>
using namespace std;
int main() {
    int v, n;
    cin >> v >> n;
    vector<int> volym(n + 1);
    vector<vector<bool>> ks(n + 1, vector<bool>(v + 1, 0));
    for (int i = 0; i <= n; i++)ks[i][0] = 1;
    for (int i = 1; i <= n; i++)cin >> volym[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            if (ks[i - 1][j])ks[i][j] = ks[i - 1][j];
            else if (j >= volym[i])ks[i][j] = ks[i - 1][j - volym[i]];
        }
    }
    /*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=v;j++)cout<<ks[i][j]<<' ';
            cout<<endl;
        }
    */
    for (int i = 0; i <= v; i++) {
        if (ks[n][v - i]) { cout << i; return 0; }
    }
    return 0;
}