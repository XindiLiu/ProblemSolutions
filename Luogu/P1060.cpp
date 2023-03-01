#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> feiyong(m);
    vector<int> jiazhi(m);
    vector<int> vaska(n + 1, 0);
    int jinput;
    for (int i = 0; i < m; i++) {
        cin >> feiyong[i] >> jinput;
        jiazhi[i] = feiyong[i] * jinput;
    }
    for (int j = 0; j < m; j++) {
        for (int i = n; i >= feiyong[j]; i--) {
            vaska[i] = max(vaska[i], vaska[i - feiyong[j]] + jiazhi[j]);
        }
    }
    int svar;
    for (int i = n; i >= 0; i--) {
        if (vaska[i]) { svar = vaska[i]; break; }
    }
    cout << svar;
    return 0;
}