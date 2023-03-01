class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> a;
    int numRollsToTarget(int n, int k, int target) {
        k -= 1;
        target -= n;
        a = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 1; j <= k; ++j) {

        //     }
        // }
        return rec(n, k, target);
    }
    int rec(int n, int& k, int target) {
        if (n == 1) {
            if (target >= 0 && target <= k) {
                return 1;
            }
            else return 0;
        }
        else if (a[n][target] != -1) {
            return a[n][target];
        }

        int sum = 0;
        int i1 = target - (n - 1) * k;
        for (int i = max(i1, 0); i <= k && i <= target; ++i) {
            sum = (sum + rec(n - 1, k, target - i)) % mod;

        }
        return a[n][target] = sum;
    }
};