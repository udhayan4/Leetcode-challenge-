#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // \U0001f522 Sort to group duplicates
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, 0, target, current, result);
        return result;
    }

    void backtrack(vector<int>& nums, int index, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current); // ✅ Valid combination
            return;
        }
        if (target < 0 || index >= nums.size()) return; // ❌ Prune

        // ✅ Include current
        current.push_back(nums[index]);
        backtrack(nums, index + 1, target - nums[index], current, result);
        current.pop_back(); // \U0001f519 Backtrack

        // ❌ Exclude and skip duplicates
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index]) next++;
        backtrack(nums, next, target, current, result);
    }
};