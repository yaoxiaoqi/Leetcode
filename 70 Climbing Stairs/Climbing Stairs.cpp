class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums(n+1, 0);
        if (n >= 1)
            nums[1] = 1;
        if (n >= 2)
            nums[2] = 2;
        for (int i = 3; i <= n; i++) {
            nums[i] = nums[i-2] + nums[i-1];
        }
        return nums[n];
    }
};
