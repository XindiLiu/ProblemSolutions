class Solution {
public:
    vector<int> p;
    vector<int> sz;
    int root(int x) {
        int curr = x;
        while (p[curr] != curr) {
            curr = p[curr];
        }
        return p[x] = curr;
    }
    void merge(int x, int y) {
        int xp = root(x);
        int yp = root(y);
        if (xp != yp) {
            if (sz[xp] > sz[yp]) {
                p[yp] = xp;
                sz[xp] += sz[yp];
            }
            else {
                p[xp] = yp;
                sz[yp] += sz[xp];
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        sz = vector<int>(n + 1, 1);
        p = vector<int>(n + 1);
        for (int i = 1; i < n; ++i) {
            p[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (root(edges[i][0]) == root(edges[i][1])) {
                return edges[i];
            }
            merge(edges[i][0], edges[i][1]);
        }
        return edges[0];
    }
};
