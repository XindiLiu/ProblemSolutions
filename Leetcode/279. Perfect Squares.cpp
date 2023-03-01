class Solution {
public:
    int numSquares(int n) {
        vector<int> a(n + 1, INT_MAX);
        a[0] = 0;
        for (int i = 1; i * i <= n; ++i) {
            int i2 = i * i;
            a[i2] = 1;
            for (int j = i2 + 1; j <= n; ++j) {
                a[j] = min(a[j], a[j - i2] + 1);
            }
        }
        return a[n];
    }
};