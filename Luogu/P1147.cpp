#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
typedef pair<int, int> pii;
int main() {
    int m, s = 0, x, a0;
    scanf("%d", &m);
    vector<pii> b(9999999);
    m += m;
    int rm = sqrt(m);
    for (int i = rm; i >= 2; --i) {
        if (!(m % i)) {
            x = m / i;
            if (!(i % 2) && !(x % 2))continue;
            a0 = (x + 1 - i) / 2;
            b[s].first = a0;
            b[s].second = a0 + i - 1;
            ++s;
        }
    }
    for (int i = 0; i < s; i++) {
        cout << b[i].first << ' ' << b[i].second << endl;
    }
    return 0;
}
