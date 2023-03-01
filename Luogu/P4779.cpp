#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;
struct edge {
    int to;
    int w;
    edge(int t1, int w1) :to(t1), w(w1) {};
};
struct node {
    int i, d;
    node(int i1, int d1) :i(i1), d(d1) {};
    bool operator > (const node& a) const {
        return this->d > a.d;
    }
};

template <class T> class bheap {
    int n;
    int sz;
    vector<T> h;
    vector<int> arr; // index to position in the heap
    function<bool(T, T)> cp;
public:
    bheap(int _n, function<bool(T, T)> c) : n(_n), sz(0), cp(c) {
        h = vector<T>(n + 1);
        arr = vector<int>(n + 1, 0);
    };
    T top() { return h[1]; }
    bool empty() { return sz == 0; };
    void push(T a) {
        if (arr[a]) {
            up(arr[a]);
        }
        else {
            sz++;
            h[sz] = a;
            arr[a] = sz;
            up(sz);
        }
    }
    void pop() {
        h[1] = h[sz];
        arr[h[sz]] = 1;
        sz--;
        down(1);
    }
    void up(int x) {
        int px = x >> 1;
        while (x > 1 && !cp(h[x], h[px])) {
            swap(arr[h[x]], arr[h[px]]);
            swap(h[x], h[px]);
            x = px;
            px = x >> 1;
        }
    }
    void down(int x) {
        while (x << 1 <= sz) {
            int c = x << 1;
            if (c + 1 <= sz && cp(h[c], h[c + 1])) c += 1;
            if (cp(h[c], h[x])) break;
            swap(arr[h[c]], arr[h[x]]);
            swap(h[c], h[x]);
            x = c;
        }
        // if (x * 2 > sz) { return; }
        // int c1 = x << 1;
        // int c2 = (x << 1) + 1;
        // int min12 = cp(h[c1], h[c2]) ? c2 : c1;
        // if (!cp(h[min12], h[x])) {
        //     swap(arr[h[min12]], arr[h[x]]);
        //     swap(h[min12], h[x]);
        //     down(min12);
        // }
    }
};

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s;
    n = read();
    m = read();
    s = read();
    vi dis;
    vi visit;
    visit = vi(n + 1, 0);
    vector<list<edge>> from;
    from = vector<list<edge>>(n + 1);
    dis = vi(n + 1, INT_MAX);
    dis[s] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        u = read();
        v = read();
        w = read();
        from[u].push_back(edge(v, w));
    }
    bheap<int> q(n, [&dis] (int a, int b) {return dis[a] > dis[b]; });
    q.push(s);

    while (!q.empty()) {
        int i = q.top();
        q.pop();
        if (!visit[i]) {
            visit[i] = 1;
            for (auto e : from[i]) {
                if (dis[i] + e.w < dis[e.to]) {
                    dis[e.to] = dis[i] + e.w;
                    q.push(e.to);
                }
            }
        }
    }
    cout << dis[1];
    for (int i = 2; i <= n; ++i) {
        cout << ' ' << dis[i];
    }
    return 0;
}