class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long int total_len = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                total_len = (s[i] - '0') * (total_len);
            }
            else {
                total_len++;
            }
        }


        for (int i = n - 1; i >= 0; i--) {
            k = k % total_len;
            if (k == 0 and !isdigit(s[i])) {
                return string(1, s[i]);
            }

            if (isdigit(s[i])) {
                total_len /= s[i] - '0';
            }
            else {
                total_len--;
            }
        }

        return "";
    }
};