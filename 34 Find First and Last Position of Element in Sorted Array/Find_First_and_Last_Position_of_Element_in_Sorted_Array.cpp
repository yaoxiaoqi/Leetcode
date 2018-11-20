class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer = {-1, -1};
        if (nums.size() == 0) {
            return answer;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                int tmp = mid;
                while (nums[--tmp] == target) {
                    if (tmp <= 0) {
                        tmp = 0;
                        break;
                    };
                }
                left = nums[tmp] == target? tmp: tmp + 1;
                while (nums[++mid] == target) {
                    if (mid == nums.size() - 1) break;
                }
                right = nums[mid] == target? mid: mid - 1;
                break;
            }
        }
        if (nums[left] == target) {
            answer[0] = left;
            answer[1] = right;
            return answer;
        }
        return answer;
    }
};
