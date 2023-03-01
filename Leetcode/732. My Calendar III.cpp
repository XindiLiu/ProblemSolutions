struct node {
    int v;
    int lazy = 0;
    int l, r;
    node* left = nullptr;
    node* right = nullptr;
    node(int v, int l, int r):v(v), l(l), r(r) {}
    void createchilds() {
        int mid = (l + r) / 2;
        left = new node(v, l, mid);
        right = new node(v, mid + 1, r);
        left->lazy = lazy;
        right->lazy = lazy;
    }
    void increment(int lr, int rr) {
        if (l == r) {
            v++;
            return;
        }
        if (l >= lr && r <= rr) {
            v++;
            lazy++;
            return;
        }
        if (left == nullptr) {
            createchilds();
        }
        else if (r > l && lazy) {
            pushdown();
        }
        lazy = 0;
        int mid = (l + r) / 2;
        if (lr <= mid) {
            left->increment(lr, rr);
        }
        if (rr > mid) {
            right->increment(lr, rr);
        }
        v = max(left->v, right->v);
    }
    int kboking(int lr, int rr) {
        if (l >= lr && r <= rr) {
            return v;
        }
        if (left == nullptr) {
            createchilds();
        }
        else if (r > l && lazy) {
            pushdown();
        }
        lazy = 0;
        int maxelem = 0;
        int mid = (l + r) / 2;
        if (lr <= mid) {
            maxelem = max(maxelem, left->kboking(lr, rr));
        }
        if (rr > mid) {
            maxelem = max(maxelem, right->kboking(lr, rr));
        }
        return maxelem;
    }
    void pushdown() {
        left->v += lazy;
        left->lazy += lazy;
        right->v += lazy;
        right->lazy += lazy;
    }
};

class MyCalendarThree {
public:
    node* root;
    MyCalendarThree() {
        root = new node(0, 0, 1e9);
    }

    int book(int start, int end) {
        root->increment(start, end - 1);
        int ret = root->v;
        return ret;
    }
};
