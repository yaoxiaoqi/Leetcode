class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;
        vector<int> nums(N+1, 0);
        nums[1] = 1;
        return fibs(nums, N);
    }
    
    int fibs(vector<int>& nums, int N) {
        if (N == 0) return nums[N];
        if (nums[N] > 0) return nums[N];
        nums[N] = fibs(nums, N-1) + fibs(nums, N-2);
        return nums[N];
    }
};
