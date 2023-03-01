#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, svar1 = 1, svar2 = 1;
    vector<int> dd(101);
    while (scanf("%d", &dd[n]) != EOF)n++;
    vector<int> lj(n, 1);
    vector<int> xx(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dd[i] <= dd[j]) {
                if (lj[i] < lj[j] + 1)lj[i] = lj[j] + 1;
            }
            else {
                if (xx[i] < xx[j] + 1)xx[i] = xx[j] + 1;
            }
        }
        if (lj[i] > svar1)svar1 = lj[i];
        if (xx[i] > svar2)svar2 = xx[i];
    }

    /*
    for(int i=0;i<n;i++)cout<<lj[i]<<' ';
    cout<<endl;
    for(int i=0;i<n;i++)cout<<xx[i]<<' ';
    */
    cout << svar1 << endl << svar2;
    return 0;
}