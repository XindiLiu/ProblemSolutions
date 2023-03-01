class Solution {
public:
    int fact[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    int pow10[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int start[10] = {1,9, 90, 738, 5274, 32490, 168570, 712890, 2345850, 5611770};
    int countSpecialNumbers(int n) {
        vector<int> used(10, 0);

        int d = log10(n);
        if (d == 0)return n;
        vector<int> digits(d + 1, 0);
        for (int j = 0; j < d; ++j) {
            digits[j] = (n % pow10[j + 1] / pow10[j]);
            n -= n % pow10[j + 1];
        }
        digits[d] = (n / pow10[d]);

        int ans = start[d]; // 0 to 10^d-1

        for (int i = d; i >= 0; --i) {
            // if (used[digits[i]]) {
            //     break;
            // }
            int avaiable1 = 0, avaiable2 = 0;
            for (int ii = 0; ii <= 9; ++ii) {
                if (!used[ii]) {
                    if (ii < digits[i] || (i == 0 && ii <= digits[i])) { avaiable1++; }
                    avaiable2++;
                }
                if (used[ii] > 1) {
                    return ans;
                }
            }

            if (i == d) { avaiable1 = digits[i] - 1; }
            avaiable2 -= 1;
            if (avaiable2 < i) {
                break;
            }
            int add = avaiable1;
            // for (int j = avaiable2 - 1; j >= avaiable2 - i; --j) {
            //     add *= j;
            // }
            if (i >= 1) {
                add *= fact[avaiable2] / fact[avaiable2 - i];
            }
            ans += add;

            used[digits[i]] += 1;
            // if (i == 1 && !used[0]) {
            //     ans += 1;
            // }
        }
        return ans;
    }

};