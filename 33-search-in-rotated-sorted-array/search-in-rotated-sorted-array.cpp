class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary(nums, target, 0, nums.size() - 1);
    }

    int binary(vector<int>& nums, int target, int s, int e) {
        if (s > e) return -1;
        int mid = s + (e - s) / 2;

        if (nums[mid] == target) return mid;

        if (nums[mid] >= nums[s]) {
            if (target >= nums[s] && target <= nums[mid])
                return binary(nums, target, s, mid - 1);
            else
                return binary(nums, target, mid + 1, e);
        }

        if (target >= nums[mid] && target <= nums[e])
            return binary(nums, target, mid + 1, e);
        else
            return binary(nums, target, s, mid - 1);
    }
};