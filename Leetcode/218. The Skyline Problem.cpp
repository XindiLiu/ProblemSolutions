struct node {
    node* left = nullptr;
    node* right = nullptr;
    int lazy;
    int high; // highest height 
    int low; // lowest height 
    int l, r; // bounds
    bool leaf; // if hight equal for all subnodes
    node(int v, int l, int r): high(v), low(v), lazy(0), l(l), r(r), left(nullptr), right(nullptr), leaf(true) {}
    void createchilds() {
        int m = (l + r) >> 1;
        left = new node(high, l, m);
        right = new node(high, m + 1, r);
    }
    void setv(int cl, int cr, int newv) {
        // node range is subset of the changed range 
        if (cl <= l && r <= cr) {
            // building higher than all others in the range
            if (newv >= high) {
                low = high = newv;
                if (!leaf) {
                    leaf = true;
                }
            }
            else {
                // modify value and set lazy mark
                high = max(high, newv);
                low = max(low, newv);
            }
            lazy = max(lazy, newv);
            return;
        }
        // If new height lower than all buildings.
        if ((leaf && newv <= high) || newv <= low) {
            return;
        }
        if (left == nullptr) {
            createchilds();
        }
        // pushdown lazy mark
        if (lazy != 0 && l != r) {
            pushdown();
        }
        int m = (l + r) >> 1;
        if (cl <= m)left->setv(cl, cr, newv);
        if (cr > m)right->setv(cl, cr, newv);
        high = max(left->high, right->high);
        low = min(left->low, right->low);
        leaf = left->leaf && right->leaf && left->high == right->high;
    }
    int maxv(int i) {
        if (leaf) { return high; }
        if (lazy != 0 && l != r) {
            pushdown();
        }
        if (i <= (l + r) >> 1) {
            return left->maxv(i);
        }
        else {
            return right->maxv(i);
        }

    }
    void pushdown() {
        left->lazy = max(left->lazy, lazy);
        left->high = max(left->high, left->lazy);
        left->low = max(left->low, left->lazy);
        right->lazy = max(right->lazy, lazy);
        right->high = max(right->high, right->lazy);
        right->low = max(right->low, right->lazy);
    }

};
node* root;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        map<int, int> vlines;
        for (int i = 0; i < n; ++i) {
            vlines[buildings[i][0]] = 0;
            vlines[buildings[i][1]] = 0;
        }
        int i = 1;
        for (auto kv = vlines.begin(); kv != vlines.end(); kv++) {
            kv->second = i++;
        }
        root = new node(0, 1, vlines.size());
        for (int i = 0; i < n; ++i) {
            root->setv(vlines[buildings[i][0]], vlines[buildings[i][1]] - 1, buildings[i][2]);
            int a = 1;
        }
        vector<vector<int>> ans(2 * n, vector<int>(2));
        int ansi = 0;
        int prev = 0;
        for (auto kv = vlines.begin(); kv != vlines.end(); kv++) {
            int currh = root->maxv(kv->second);
            if (currh != prev) {
                ans[ansi][0] = kv->first;
                ans[ansi][1] = currh;
                prev = currh;
                ansi++;
            }
        }
        ans.resize(ansi);
        return ans;
    }
};