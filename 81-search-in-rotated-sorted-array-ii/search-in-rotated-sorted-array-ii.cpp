class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            while (left < nums.size() - 1 && nums[left] == nums[left + 1])
                left++;
            while (right > 0 && nums[right] == nums[right - 1])
                right--;
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1; // Target is in the left half
                else
                    left = mid + 1; // Target is in the right half
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1; // Target is in the right half
                else
                    right = mid - 1; // Target is in the left half
            }
        }

        return false; // Target not found
    }
};