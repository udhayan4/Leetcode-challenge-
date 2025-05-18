class Solution {
private:
    void SetQueen(vector<vector<string>>& ans, vector<vector<int>> checkBox,vector<string>temp, int n,int row) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++)
        if (checkBox[row][col] == 0) {
            vector<vector<int>>newCheckBox=checkBox;
            string rowStr(n, '.');
            rowStr[col] = 'Q';
            temp.push_back(rowStr);

            //row and col
            for(int i=0;i<n;i++){
                newCheckBox[row][i]=1;   //row
                newCheckBox[i][col]=1;   //col
            }

            //diagonal
            for(int p1=row,p2=col;p1<n&&p2<n;p1++,p2++){
                if(newCheckBox[p1][p2]==0) newCheckBox[p1][p2]=1;
            }
            for(int p1=row,p2=col;p1>=0&&p2>=0;p1--,p2--){
                if(newCheckBox[p1][p2]==0) newCheckBox[p1][p2]=1;
            }
            for(int p1=row,p2=col;p1<n&&p2>=0;p1++,p2--){
                if(newCheckBox[p1][p2]==0) newCheckBox[p1][p2]=1;
            }
            for(int p1=row,p2=col;p1>=0&&p2<n;p1--,p2++){
                if(newCheckBox[p1][p2]==0) newCheckBox[p1][p2]=1;
            }
            SetQueen(ans,newCheckBox,temp,n,row+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> checkBox(n, vector<int>(n, 0));
        int row = 0;
        vector<string>temp;
        SetQueen(ans, checkBox, temp, n,row);
        return ans;
    }
};