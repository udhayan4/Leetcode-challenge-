class Solution {
public:
    /*
    bool ispalindrome(string& str, int start, int end) {
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    */

    int solve(const string& str, int i, int j, vector<vector<int>>& dp,vector<vector<bool>>& ispalin) {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // if(isPalindrome(str,i,j)) return dp[i][j]=0;
        if(ispalin[i][j]) return dp[i][j]=0;

        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            // if(isPalindrome(str,i,k)){
                // if(dp[i][k]==0){
                    if(ispalin[i][k]){
                int cut=1+solve(str,k+1,j,dp,ispalin);
                 mini=min(cut,mini);
            }
        }
        return dp[i][j]=mini;
    }

    int minCut(string str) {
        int n=str.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        /*
        for(int i=0;i<n;i++){
            dp[i][i]=0;
            for(int j=i+1;j<n;j++){
                if(ispalindrome(str,i,j)){
                    dp[i][j]=0;
                }
            }
        }
        */
        vector<vector<bool>> isplain(n,vector<bool>(n,false));

        for(int len=0;len<n;len++){
            for(int j=0;j+len<n;j++ ){
                int end=j+len;
                if(len==0)isplain[j][j]=true;
                else if(len==1) isplain[j][end]=str[j]==str[end]?true:false;
                else{
                    isplain[j][end]=(str[j]==str[end] && isplain[j+1][end-1]);
                }
            }
        }
        return solve(str,0,n-1,dp,isplain);
    }
};