class Solution {
public:
    int solveRE(string &word1, string &word2, int i, int j) {
        // base case
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;
        // ek case
        int ans = INT_MAX;
        if (word1[i] == word2[j])
            ans = 0 + solveRE(word1, word2, i + 1, j + 1);
        else {
            int ins = 1 + solveRE(word1, word2, i, j + 1);
            int del = 1 + solveRE(word1, word2, i + 1, j);
            int rep = 1 + solveRE(word1, word2, i + 1, j + 1);
            ans = min(ins, min(del, rep));
        }
        return ans;
    }
    int solveTD(string &word1, string &word2, int i, int j, vector<vector<int>>&dp) {
        // base case
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        // ek case
        int ans = INT_MAX;
        if (word1[i] == word2[j])
            ans = 0 + solveTD(word1, word2, i + 1, j + 1,dp);
        else {
            int ins = 1 + solveTD(word1, word2, i, j + 1,dp);
            int del = 1 + solveTD(word1, word2, i + 1, j,dp);
            int rep = 1 + solveTD(word1, word2, i + 1, j + 1,dp);
            ans = min(ins, min(del, rep));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solveBU(string &word1, string &word2){
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int j = 0; j<=word2.size();j++)
            dp[word1.size()][j] = word2.size() - j;
        for(int i = 0; i<=word1.size();i++)
            dp[i][word2.size()] = word1.size() - i;
        for(int i = word1.size()-1;i>=0;i--){
            for(int j = word2.size()-1;j>=0;j--){
                int ans = INT_MAX;
                if (word1[i] == word2[j])
                    ans = 0 + dp[i + 1][ j + 1];
                else {
                    int ins = 1 + dp[i][j + 1];
                    int del = 1 + dp[i + 1][j];
                    int rep = 1 + dp[i + 1][j + 1];
                    ans = min(ins, min(del, rep));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int solveSO(string &word1, string &word2){
        vector<int>curr(word2.size()+1,0);
        vector<int>next(word2.size()+1,0);
        for(int j = 0; j<=word2.size();j++)
            next[j] = word2.size() - j;
        for(int i = word1.size()-1;i>=0;i--){
            curr[word2.size()]=word1.size() - i;
            for(int j = word2.size()-1;j>=0;j--){
                int ans = INT_MAX;
                if (word1[i] == word2[j])
                    ans = 0 + next[ j + 1];
                else {
                    int ins = 1 + curr[j + 1];
                    int del = 1 + next[j];
                    int rep = 1 + next[j + 1];
                    ans = min(ins, min(del, rep));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        // return solveRE(word1, word2, 0, 0);
        // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        // return solveTD(word1, word2, 0, 0,dp);
        // return solveBU(word1,word2);
        return solveSO(word1,word2);
    }
};