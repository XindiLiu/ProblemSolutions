class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> bin;
    int numberOfWays(int startPos, int endPos, int k) {
        if (startPos > endPos) {
            swap(startPos, endPos);
        }
        int right = endPos - startPos;
        int left = 0;
        if ((k - right) % 2 != 0 || right > k) {
            return 0;
        }
        left = (k - right) / 2;
        right += left;
        bin = vector<vector<int>>(k + 1, vector<int>(left + 1, -1));
        return binomial(k, left);
    }
    int binomial(int n, int k) {
        if (k == 0) {
            return 1;
        }
        else if (n == 0) {
            return 0;
        }
        else if (bin[n][k] != -1) {
            return bin[n][k];
        }
        else return bin[n][k] = (binomial(n - 1, k - 1) + binomial(n - 1, k)) % mod;
    }
};