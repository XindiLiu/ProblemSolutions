#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> m{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};
string f(int t);
int main() {
    scanf("%d", &n);
    cout << f(n);
    return 0;
}
string f(int t) {
    string r;
    int c = upper_bound(m.begin(), m.end(), t) - m.begin() - 1;
    while (t > 0) {
        if (t >= m[c]) {
            if (c == 1)r += "2+";
            else if (c == 0)r += "2(0)+";
            else r += "2(" + f(c) + ")+";
            t -= m[c];
        }
        --c;
    }
    r.pop_back();
    return r;
}