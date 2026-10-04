class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1) cntFresh++;
            }
        }
        int time = 0;
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            time = max(time,tm);
            int dr[]= {-1,0,1,0};
            int dc[]= {0,1,0,-1};
            for(int i =0;i<4;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol},tm+1});
                    cnt++;
                }
            }
        }
        return (cnt != cntFresh) ? -1 : time;
    }
};