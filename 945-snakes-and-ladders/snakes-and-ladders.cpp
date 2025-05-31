class Solution {
    pair<int,int> find(int val,int n){
        int r=n-(val-1)/n-1,c=(val-1)%n;
        if(r%2==n%2) return {r,n-1-c};
        return {r,c};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        int level=0,n=board.size();
        q.push(1);
        vector<vector<int>>vis(n,vector<int>(n,-1));
        vis[n-1][0]=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr=q.front(); q.pop();
                if(curr==n*n) return level;
                for(int i=1;i<=6;i++){
                    if(curr+i>n*n) continue;
                    auto [r,c]=find(curr+i,n);
                    if(vis[r][c]!=-1) continue;
                    if(board[r][c]==-1) q.push(curr+i);
                    else q.push(board[r][c]);
                    vis[r][c]=1;
                }   
            }
            level++;
        }
        return -1;
    }
};