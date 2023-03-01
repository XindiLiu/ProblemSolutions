#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int pot(int b, int e);
int main() {
    int x, y, ap = 0;
    scanf("%d%d", &x, &y);
    if (x == y) { cout << 1; return 0; }
    int xy = y / x;
    if (xy < 2 || y % x) { cout << 0; return 0; }
    int rxy = sqrt(xy);
    int i = 2;
    while (xy > 1) {
        if (!(xy % i)) {
            xy /= i;
            while (!(xy % i))xy /= i;
            ++ap;
        }
        ++i;
    }
    cout << pot(2, ap);
    return 0;
}
int pot(int b, int e) {
    if (e == 1)return b;
    int r = pot(b, e / 2);
    r *= r;
    if (e % 2)r *= b;
    return r;
}