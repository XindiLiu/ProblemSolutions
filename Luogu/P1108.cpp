#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main() {
    int n, mlen = 1, anme = 0;
    cin >> n;
    vector<int> jg(n);
    for (int i = 0; i < n; i++)scanf("%d", &jg[i]);
    vector<int> las(n, 0);
    vector<int> am(n, 0);
    am[0] = 1;
    las[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (jg[i] < jg[j]) {
                if (las[i] < las[j]) {
                    las[i] = las[j];
                    am[i] = am[j];
                }
                else if (las[i] == las[j]) {
                    am[i] += am[j];
                }
            }
            else if (jg[i] == jg[j] && las[i] + 1 == las[j])am[j] = 0;
        }
        las[i] += 1;
        if (!am[i])am[i] = 1;
        if (mlen < las[i]) { mlen = las[i]; }
    }
    for (int i = 0; i < n; i++)if (las[i] == mlen)anme += am[i];
    cout << mlen << ' ' << anme;
    return 0;
}