class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.0) return 1.0;
        if (n == INT_MIN) return myPow(x, -2147483647) / x;
        double res = 1.0;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        while(n > 0) {
            if (n & 1 == 1) {
                res *= x;
            }
            if (res == 0) {
                break;
            }
            x = x * x;
            n >>= 1;
        }
        return res;
    }
};
