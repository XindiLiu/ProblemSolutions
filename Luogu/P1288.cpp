#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define yes {cout<<"YES";return 0;}
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)scanf("%d", &c[i]);
    int a = 1;
    while (c[a - 1] != 0)++a;
    if (a % 2 == 0)yes
        a = 1;
    while (c[n - a] != 0)++a;
    if (a % 2 == 0)yes
        cout << "NO";
    return 0;
}