#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef list<int> li;
typedef list<int>::iterator lit;
typedef vector<lit> vlit;
li q;
vi skill;
vi bg;
vlit it;
struct pa {
    int left;
    int right;
    int diff;
    pa(int l, int r) : left(l), right(r), diff(abs(skill[l] - skill[r])) {}
};
int next(int x) {
    lit a = it[x];
    lit b = ++it[x];
    it[x] = a;
    if (b == q.end()) {
        return -1;
    }
    else {
        return *b;
    }
};

int prev(int x) {
    lit a = it[x];
    if (a == q.begin()) {
        return -1;
    }
    else {
        lit b = --it[x];
        it[x] = a;
        return *b;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    bg = vi(n);
    skill = vi(n);
    q = li();
    it = vlit(n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            bg[i] = 1;
        }
        else if (c == 'G') {
            bg[i] = 0;
        }
        q.push_back(i);
        it[i] = --q.end();
    }
    for (int i = 0; i < n; i++) {
        cin >> skill[i];
    }
    auto comp = [](pa& a, pa& b) { return (a.diff == b.diff) ? (a.left > b.left) : (a.diff > b.diff); };
    auto minheap = priority_queue<pa, vector<pa>, decltype(comp)> (comp);

    for (int i = 0; i < n - 1; i++) {
        if (bg[i] != bg[i + 1]) {
            minheap.push(pa(i, i + 1));
        }
    }

    int out = 0;
    vi ans1(n);
    vi ans2(n);
    vi exist(n, 1); // whatever i exist in the queue
    while (!minheap.empty()) {
        auto top = minheap.top();
        minheap.pop();
        if (!exist[top.left] || !exist[top.right]) { // the pair does no longer exist
            continue;
        }
        else {
            ans1[out] = top.left + 1;
            ans2[out] = top.right + 1;
            out++;
            int pr = prev(top.left);
            int nx = next(top.right);
            if (pr != -1 && nx != -1) { // pair not at begining or end, add new pair
                if (bg[pr] != bg[nx]) {
                    minheap.push(pa(pr, nx));
                }
            }
            q.erase(it[top.left]);
            q.erase(it[top.right]);
            exist[top.left] = 0;
            exist[top.right] = 0;
        }
    }

    cout << out << endl;
    for (int i = 0; i < out; i++) {
        cout << ans1[i] << ' ' << ans2[i] << endl;
    }

    return 0;
}
