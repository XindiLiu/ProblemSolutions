class Solution {
public:
    // union find set 
    vector<int> p;
    vector<int> sz;
    int find(int x) {
        int curr = x;
        while (p[curr] != curr) {
            curr = p[curr];
        }
        p[x] = curr;
        return p[x];
    }
    void unionset(int x, int y) {
        if (find(x) != find(y)) {
            int px = p[x];
            int py = p[y];
            if (sz[px] > sz[py]) {
                p[py] = px;
                sz[px] += sz[py];
            }
            else {
                p[px] = py;
                sz[py] += sz[px];
            }
        }
    }
    bool eq(int x, int y) {
        return find(x) == find(y);
    }
    bool equationsPossible(vector<string>& equations) {
        p = vector<int>(26);
        sz = vector<int>(26, 1);
        for (int i = 0; i < 26; ++i) {
            p[i] = i;
        }
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '=') {
                unionset(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        for (int i = 0; i < equations.size(); ++i) {
            if (equations[i][1] == '!') {
                if (eq(equations[i][0] - 'a', equations[i][3] - 'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};