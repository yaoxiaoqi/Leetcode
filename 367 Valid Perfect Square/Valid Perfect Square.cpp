class Solution {
public:
    bool isPerfectSquare(int sum) {
        if (sum <= 1) return true;
        long left = 0, right = sum / 2;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid > sum) {
                right = mid - 1;
            } else if (mid * mid < sum) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
