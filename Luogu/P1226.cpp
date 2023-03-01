#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f(ll b, ll p, ll k);
int main() {
    ll b, p, k;
    cin >> b >> p >> k;
    cout << b << '^' << p << " mod " << k << "=" << f(b, p, k);
    return 0;
}
ll f(ll b, ll p, ll k) {
    if (p == 0) return 1;
    ll m = f(b, p / 2, k);
    m *= m;
    m = m % k;
    if (p % 2)m *= b % k;
    return m % k;
}