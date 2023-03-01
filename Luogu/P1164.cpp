#include <bits/stdc++.h>
using namespace std;
vector<int> cai;
vector<vector<int>> cishu;
int n, m;
int main() {

    cin >> n >> m;
    cai.resize(n + 1);
    for (int i = 1; i <= n; i++)cin >> cai[i];
    cishu.assign(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)cishu[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cishu[i][j] = cishu[i - 1][j] + ((j >= cai[i]) ? (cishu[i - 1][j - cai[i]]) : 0);
        }
    }
    /*
    cout<<"  ";
    for(int i=0;i<=m;i++)cout<<i<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<' ';
        for(int j=0;j<=m;j++){
            cout<<cishu[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    cout << cishu[n][m];
    return 0;
}