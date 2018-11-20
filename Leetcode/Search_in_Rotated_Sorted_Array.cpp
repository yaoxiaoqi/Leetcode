class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int pivot = searchPivot(nums);
        int left = 0, right = int(nums.size()) - 1;
        if (pivot >= 0) {
            if (nums[pivot] == target) {
                return pivot;
            } else if (nums[pivot] > target) {
                return -1;
            } else {
                if (target > nums[right]) {
                    right = pivot - 1;
                } else {
                    left = pivot + 1;
                }
            }
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
private:
    int searchPivot(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int left = 0;
        int right = int(nums.size()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // in case of overflow
            if (right - left <= 1) {
                if (nums[right] < nums[left]) {
                    return right;
                } else {
                    break;
                }
            }
            if (nums[left] > nums[mid]) {
                right = mid;
            } else if (nums[right] < nums[mid]) {
                left = mid;
            } else {
                break;
            }
        }
        return 0;
    }
};
