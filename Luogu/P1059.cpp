#include <bits/stdc++.h>
using namespace std;
int n, ar = 0;
vector<int> svar;
vector<int> a;
vector<bool> r(101, 1);
void ms(int b, int e);
int main() {

    cin >> n;
    a.resize(n);
    svar.resize(n);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    ms(0, n - 1);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            r[i] = 0;
            ar++;
        }
    }
    cout << n - ar << endl;
    for (int i = 0; i < n; i++) {
        if (r[i])cout << a[i] << ' ';
    }
    return 0;
}
void ms(int b, int e) {
    if (b == e)return;
    int mid = (b + e) >> 1;
    ms(b, mid);
    ms(mid + 1, e);
    int i = b, j = mid + 1, k = b;
    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            svar[k] = a[i];
            i++;
        }
        else {
            svar[k] = a[j];
            j++;
        }
        k++;
    }
    if (i <= mid)while (i <= mid) { svar[k] = a[i]; i++; k++; }
    else while (j <= e) { svar[k] = a[j]; j++; k++; }
    for (int p = b; p <= e; p++)a[p] = svar[p];
    /*
        cout<<b<<'~'<<e<<' ';
        for(int i=0;i<n;i++)cout<<a[i]<<' ';
        cout<<endl;
    */
}
/*
10
20 40 32 67 40 20 89 300 400 15
*/