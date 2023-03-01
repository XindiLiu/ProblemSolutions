#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    int n, k, j;
    cin >> n >> k;
    vector<int> ks(k);
    vector<int> cs(k);
    vector<int> mt(n + 2, 0);
    for (int i = 0; i < k; i++) { cin >> ks[i] >> cs[i]; }
    j = k - 1;
    for (int i = n; i >= 1; i--) {
        if (ks[j] != i)mt[i] = mt[i + 1] + 1;
        else {
            while (ks[j] == i) {
                if (mt[i] < mt[i + cs[j]])mt[i] = mt[i + cs[j]];
                j--;
            }
        }
    }
    cout << mt[1];
    return 0;
}
