#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
const string stan = "Stan wins\n";
const string ollie = "Ollie wins\n";
int main() {
    int c, m, n, r, k, a;
    string ut = "";
    scanf("%d", &c);
    for (int tc = 0; tc < c; ++tc) {
        scanf("%d%d", &m, &n);
        k = 0;
        while (n > 0) {
            if (m == n) { ut += stan; break; }
            if (m < n)swap(m, n);
            a = m / n;
            if (a > 1) {
                if (k % 2 == 0)ut += stan;
                else ut += ollie;
                break;
            }
            r = m - a * n;
            m = n;
            n = r;
            ++k;
        }
    }
    cout << ut;
    return 0;
}