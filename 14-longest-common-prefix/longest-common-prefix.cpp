class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());  // Sort lexicographically

        int n = strs.size();
        string result = "";

        // Compare only first and last strings after sorting
        int size = strs[0].size();
        for (int i = 0; i < size; i++) {
            if (strs[0][i] == strs[n - 1][i]) {
                result.push_back(strs[0][i]);
            } else {
                break;
            }
        }

        return result;
    }
};