typedef long long ll;
class Solution {
    char d0 = '0';
    char d9 = '9';
public:
    int myAtoi(string s) {
        int i = 0;
        ll ans = 0;
        int n = s.size();
        int sign = 1;
        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }
        while (i < n && d0 <= s[i] && d9 >= s[i]) {
            ans = ans * (ll)10 + (ll)(s[i] - d0);
            if (sign == 1 && ans >= (ll)INT_MAX) {
                return INT_MAX;
            }
            else if (sign == -1 && ans >= (ll)INT_MAX + (ll)1) {
                return INT_MIN;
            }

            ++i;
        }
        ans *= sign;
        return ans;
    }
};
