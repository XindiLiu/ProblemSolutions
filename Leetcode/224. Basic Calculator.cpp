class Solution {
public:
    int i;
    int n;
    string s;
    int calculate(string s1) {
        s = s1;
        n = s.size();
        i = 0;

        // while (s[i] == ' ' && i < n) {
        //     i++;
        // }

        return expr();
    }

    int expr() {
        int value = 0;
        int sign = 1;
        // bool have_parenthes;
        // if (s[i] == '(') {
        //     have_parenthes = true;
        //     i++;
        // }
        // else {
        //     have_parenthes = false;
        // }

        while (i < n) {
            // bool parenthes_closed = false;
            if (isdigit(s[i])) {
                value += sign * number();
                continue;
            }

            switch (s[i]) {
            case '+':
                sign = 1;
                i++;
                break;

            case '-':
                sign = -1;
                i++;
                break;

            case '(':
                i++;
                value += sign * expr();
                if (i < n && s[i] == ')') {
                    i++;
                }
                break;
            case ')':
                return value;
                break;

            case ' ':
                while (s[i] == ' ' && i < n) {
                    i++;
                }
                break;
            }
        }

        return value;
    }

    int number() {
        int value = 0;
        while (i < n) {
            value = value * 10 + (s[i] - '0');
            i++;
            if (i >= n || !isdigit(s[i])) {
                break;
            }
        }

        return value;
    }

    inline bool isdigit(const char& c) {
        return '0' <= c && c <= '9';
    }

};