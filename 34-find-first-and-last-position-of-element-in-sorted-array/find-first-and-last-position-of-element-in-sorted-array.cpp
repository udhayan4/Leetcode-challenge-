class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1, found = -1;
        // Standard binary search to find any occurrence
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                found = mid;
                break;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (found == -1)
            return {-1, -1};

        // Expand left and right
        int left = found, right = found;
        while (left > 0 && nums[left - 1] == target)
            --left;
        while (right < n - 1 && nums[right + 1] == target)
            ++right;
        return {left, right};
    }
};