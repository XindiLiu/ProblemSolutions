class Solution {
public:
    vector<int> p;
    int root(int x) {
        int curr = x;
        while (p[curr] != curr) {
            curr = p[curr];
        }
        return p[x] = curr;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<int> from(n + 1, -1);
        p = vector<int>(n + 1);
        for (int i = 1; i < n; ++i) {
            p[i] = i;
        }
        int ex1 = -1, ex2 = -1;
        int cycle = -1;
        for (int i = 0; i < n; ++i) {
            if (from[edges[i][1]] == -1) {
                from[edges[i][1]] = i;
            }
            else {
                ex1 = from[edges[i][1]];
                ex2 = i;
            }
            indegree[edges[i][1]]++;

            if (ex1 == -1) {
                if (root(edges[i][0]) == root(edges[i][1])) {
                    cycle = i;
                }
                p[edges[i][1]] = p[edges[i][0]];
            }
        }
        if (ex1 != -1) {
            int ex = edges[ex1][0];
            while (from[ex] != -1) {
                if (ex == edges[ex1][1]) {
                    return edges[ex1];
                }
                ex = edges[from[ex]][0];
            }
            return edges[ex2];
        }
        else return edges[cycle];
    }
};