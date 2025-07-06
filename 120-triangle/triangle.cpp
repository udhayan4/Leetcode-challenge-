class Solution {
public:

    int minsum; 
    int backtrack(vector<vector<int>>& tri , int n , int i , int j ,vector<vector<int>>& dp){
        if(i > n-1 || j > i) return INT_MAX  ; 
        if(i==n-1){
            return tri[i][j];
            // minsum = min(sum , minsum);
        }
        if(dp[i][j] != -1 ) return dp[i][j];
        int lsum = backtrack(tri, n , i+1 , j, dp);
        int rsum = backtrack(tri, n , i+1 , j+1, dp);
        return dp[i][j] = tri[i][j] +  min(lsum, rsum);     
        // sum = sum - tri[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         minsum = INT_MAX; 
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int>(rows,-1)); 
        if(rows == 1 ){
            sort(triangle[0].begin(), triangle[0].end());
            return triangle[0][0];
        } 
        // int sum = 0 ;
        return backtrack(triangle , rows, 0 , 0 , dp);
         
    }
};