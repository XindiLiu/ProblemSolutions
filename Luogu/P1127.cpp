#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vll;
typedef vector<string> vs;
const int a = 'a';
int n;
vi wo;
vii mtx;
vi novisit;
vi last;
vii first;
vi path;
int search(int w, int len) {
    novisit[w] = 0;
    path[len] = w;
    if (len == n - 1) {
        return 1;
    }
    int found = 0;

    for (int i = 0; i < first[last[w]].size(); i++) {
        if (novisit[first[last[w]][i]]) {
            found = search(first[last[w]][i], len + 1);
            if (found)
                break;
        }

    }
    novisit[w] = 1;
    return found;
};
int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    vs words = vs(n);
    wo = vi(n);
    mtx = vii(n, vi());
    last = vi(n);
    first = vii(26, vi());
    vi lastl = vi(26, 0);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        wo[i] = i;
        last[i] = *(words[i].end() - 1) - a;
        lastl[*(words[i].end() - 1) - a]++;
        first[*words[i].begin() - a].push_back(i);
    }

    sort(wo.begin(), wo.end(), [&](int a, int b) {return words[a] < words[b];});
    for (int i = 0; i < 26; i++) {
        sort(first[i].begin(), first[i].end(), [&](int a, int b) {return words[a] < words[b];});
    }

    novisit = vi(n, 1);
    path = vi(n);

    int a1 = 0, ai;
    int b1 = 0, bi;
    for (int i = 0; i < 26; i++) {
        if (first[i].size() == lastl[i]) {
            /* code */
        }
        else if (first[i].size() == lastl[i] + 1) {
            if (a1 > 0) {
                cout << "***";
                return 0;
            }
            a1++;
            ai = i;
        }
        else if (first[i].size() == lastl[i] - 1) {
            if (b1 > 0) {
                cout << "***";
                return 0;
            }
            b1++;
            bi = i;
        }
        // else {
        //     cout << "***";
        //     return 0;
        // }

    }


    for (int i = 0; i < n; i++) {
        if (words[wo[i]][0] == ai + a || (a1 == 0 && b1 == 0)) {
            int found = search(wo[i], 0);
            if (found) {
                cout << words[path[0]];
                for (int j = 1; j < n; j++) {
                    cout << '.' << words[path[j]];
                }
                return 0;
            }
        }


    }

    cout << "***";
    return 0;
}
