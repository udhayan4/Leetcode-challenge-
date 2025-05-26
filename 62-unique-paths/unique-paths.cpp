class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int total = m + n - 2;
        
        int k = std::min(m - 1, n - 1);

        long long ans = 1;
        
        for (int i = 1; i <= k; ++i) {
            ans = ans * (total - k + i) / i;
        }
        return static_cast<int>(ans);
    }
};