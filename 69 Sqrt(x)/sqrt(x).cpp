class Solution {
public:
    int mySqrt(int x) {
        int tmp = (long long int) x;
        if(tmp == 0)
            return 0;
        
        long long int left = 0, right = x;
        while(left <= right){
            // Prevent (left + right) overflow
            long long int mid = left + (right - left) / 2;
            if(mid*mid == tmp) { return int(mid); }
            else if(mid*mid < tmp) { left = mid + 1; }
            else { right = mid - 1; }
        }
        
        // End Condition: left > right
        return int(right);
    }
};
