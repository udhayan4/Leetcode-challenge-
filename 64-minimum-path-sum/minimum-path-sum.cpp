class Solution {
public:

int solve(int m,int n,vector<vector<int>>& grid) {    
   for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0 && j==0) continue;
            int left = (j > 0) ? grid[i][j - 1] : INT_MAX;
            int up   = (i > 0) ? grid[i - 1][j] : INT_MAX;
     grid[i][j] += min(left,up);
    }
   }
   return grid[m][n];
}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = solve(m-1,n-1,grid);
        return ans;
    }
};