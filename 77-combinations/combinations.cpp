class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr(k);
        dfs(1, 0, n, k, curr, result);
        return result;
    }

private:
    void dfs(int start, int depth, int n, int k, vector<int>& curr,
             vector<vector<int>>& result) {
        // If we filled all k elements, add to result
        if (depth == k) {
            result.push_back(curr);
            return;
        }

        // Pruning: Only iterate till (n - (k - depth) + 1)
        for (int i = start; i <= n - (k - depth) + 1; ++i) {
            curr[depth] = i;
            dfs(i + 1, depth + 1, n, k, curr, result);
        }
    }
};