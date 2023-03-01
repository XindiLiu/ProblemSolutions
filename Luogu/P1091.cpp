#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s = 0;
    cin >> n;
    int mid = n >> 1;
    vector<int> a(n);
    vector<int> ls(n, 1);
    vector<int> la(n, 1);
    for (int i = 0; i < n; i++)scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int ri = n - 1 - i;
        for (int j = 0; j < i; j++) {
            int rj = n - 1 - j;
            if (a[i] > a[j] && ls[i] < ls[j] + 1)ls[i] = ls[j] + 1;
            if (a[ri] > a[rj] && la[ri] < la[rj] + 1)la[ri] = la[rj] + 1;
            if (i >= mid) {
                if (ls[i] + la[i] > s)s = ls[i] + la[i];
                if (ls[ri] + la[ri] > s)s = ls[ri] + la[ri];
            }
        }
        /*
                for(int k=0;k<n;k++)cout<<ls[k]<<' ';
                cout<<endl;
                for(int k=0;k<n;k++)cout<<la[k]<<' ';
                cout<<endl;
                cout<<endl;
        */
    }
    cout << n - s + 1;
    return 0;
}