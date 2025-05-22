class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // ✨ Step 1: Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // ✨ Step 2: Start merged list with the first interval
        vector<vector<int>> merged;
        merged.emplace_back(intervals[0]);

        // ✨ Step 3: Iterate through the rest of the intervals
        for (int i = 1; i < intervals.size(); i++) {
            // \U0001f9e9 If current interval overlaps with the last merged one
            if (intervals[i][0] <= merged.back()[1]) {
                // \U0001f504 Merge them by updating the end of the last interval
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // ➕ No overlap → add current interval as is
                merged.emplace_back(intervals[i]);
            }
        }

        // \U0001f389 Return the merged result
        return merged;
    }
};