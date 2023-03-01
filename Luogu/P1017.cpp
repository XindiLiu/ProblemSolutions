#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
//#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define visa(xxxxx) {}
using namespace std;
int main() {
    int n, bas, m, t, b, pc = 1;
    cin >> n >> bas;
    if (n == 0) {
        cout << "0=0(base" << bas << ')';
        return 0;
    }
    b = -bas;
    int bb = b * b;
    int sw;
    if (n < 0) {
        for (int i = 0;; i += 2, pc *= bb) {
            if (pc > -n) { t = n + pc; sw = i; break; }
        }
    }
    else t = n;
    vector<int> r;
    pc = b;

    for (int i = 1;; i += 2, pc *= bb) {
        if (pc > t) { m = i - 1; break; }
    }
    visa(m)
        r.resize(m + 3);
    int p = 1;
    for (int i = 1; i < m; i++)p *= b;
    for (int i = m; i > 0; i -= 2) {
        visa(t)visa(p)
            int s1 = t / p;
        int s2 = ceil(double(s1) / b);
        r[i] = s2;
        r[i - 1] = s2 * b - s1;
        t -= s1 * p;
        p /= bb;
        visa(s1)visa(s2)visa(r[i])visa(r[i - 1])
    }
    r[0] = t;
    for (int i = 0; i <= m; i += 2) {
        if (r[i] >= b) {
            if (r[i + 1] > 0)r[i + 1] -= 1;
            else {
                r[i + 2] += 1;
                r[i + 1] = b - 1;
            }
            r[i] -= b;
        }
    }
    if (n < 0)r[sw] -= 1;
    int ce = 0;
    pc = 1;
    for (int i = 0; i <= m + 2; i++) { ce += r[i] * pc; pc *= bas; }
    visa(ce)
        int i = m + 2;
    while (!r[i]) { --i; }
    cout << n << '=';
    for (; i >= 0; --i) {
        if (r[i] >= 10)cout << char(r[i] - 10 + 65);
        else cout << r[i];
    }
    cout << "(base" << bas << ')';
    return 0;
}