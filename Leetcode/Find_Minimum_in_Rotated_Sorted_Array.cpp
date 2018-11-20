class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        }
        int left = 0, right = int(nums.size()) - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                return nums[left];
            }
        }
        if (left != nums.size()) return nums[left];
        return nums[0];
    }
};
