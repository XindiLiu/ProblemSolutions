#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> m;
int n, s = 0, g;
void f(int v, int h);
int main() {
    cin >> n;
    a.resize(n);
    m.resize(n);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    f(0, n);
    cout << s;
    return 0;
}
void f(int v, int h) {
    if (h - v == 1) { return; }
    int mitt = (v + h) / 2;
    f(v, mitt);
    f(mitt, h);
    g = v;
    int i = v, j = mitt;
    while (i < mitt && j < h) {
        if (a[i] > a[j]) {
            m[g] = a[i];
            ++i;
            s += h - j;
        }
        else {
            m[g] = a[j];
            ++j;
        }
        ++g;
    }
    if (i < mitt)for (int k = i; k < mitt; ++k) { m[g] = a[k]; ++g; }
    else for (int k = j; k < h; ++k) { m[g] = a[k]; ++g; }
    for (int k = v; k < h; k++)a[k] = m[k];
}