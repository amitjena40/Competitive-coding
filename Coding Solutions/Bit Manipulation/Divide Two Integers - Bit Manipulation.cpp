class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }


        long divd = labs(dividend), divs = labs(divisor), ans = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        while (divd >= divs)
        {
            long temp = divs, m = 1;
            while (temp << 1 <= divd)
            {
                temp = temp << 1;
                m = m << 1;
            }

            ans += m;
            divd -= temp;
        }

        return sign * ans;
    }
};