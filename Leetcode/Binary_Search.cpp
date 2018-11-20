class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = int(nums.size() - 1);
        while(left <= right) {
            int index = (left + right) / 2;
            int mid = nums[index];
            if (mid == target) {
                return index;
            } else if (target < mid) {
                right = index - 1;
            } else if (target > mid) {
                left = index + 1;
            }
        }
        return -1;
    }
};
