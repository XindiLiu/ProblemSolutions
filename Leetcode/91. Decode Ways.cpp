class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (s[0] == '0')return 0;
        if (n == 1)return 1;

        int ways1 = 1;
        int ways2 = 1;

        for (int i = 1; i < n; ++i) {
            int ways;
            if (s[i] != '0') {
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                    ways = ways1 + ways2;
                }
                else {
                    // ways = ways1;
                }
            }
            else {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    ways = ways2;
                }
                else return 0;
            }
            ways2 = ways1;
            ways1 = ways;
        }
        return ways1;
    }
};